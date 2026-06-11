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
 string s;
 cin>>s;
 for (int i = 0; i < s.size(); ++i)  
 {
 	if(s[i] >= 'a' && s[i]<='z'){
 		s[i]='x';
 	}
 }
 cout<<s<<endl;
 return 0;
}