#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxx = 2e5 + 5;
//int a[101];
int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
       ios_base::sync_with_stdio(false);
       cin.tie(0);
       string ans = "YES";
 int n;  
 cin>>n;
 int a[n];
 for(int i =0; i<n ;i++){
 	cin>>a[i];
 }
 sort(a,a+n);
 for(int i =0 ;i<n;i++){
 	if(a[i]== a[i+1]){
 		ans = "NO";
 	}
 }
 cout<<ans<<endl;
}