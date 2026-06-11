#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
int main(){
	#ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt", "r", stdin);
    // for writing output to output.txt
    freopen("output.txt", "w", stdout);
#endif
       ios_base::sync_with_stdio(false);
       cin.tie(0);
 int n  , cnt =0;   
 cin>>n;
 string s;  
 cin>>s;
 for(int i =0; i< s.size(); i++){  
 	if(s[i] != s[i+1]){
 		cnt++;
 	}
 } 
 cout<<cnt<<endl;  
 return 0;
}