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
  string s,t;
  cin>>s>>t;
  int a ,b;
  cin>>a>>b;
  string u;
  cin>>u;
if(u == s){
	a--;  
}
else{
	b--;
}
cout<<a<<" "<<b;
return 0;
}