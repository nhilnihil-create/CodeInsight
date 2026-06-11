/* 
* ID: juryc
* PROG: Prediction and Restriction
* LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
int n,k; cin>>n>>k;
int r,s,p; cin>>r>>s>>p;
string t; cin>>t;
array<char,3> c={'r','s','p'};
vector<array<int,3> > dp(n,{0,0,0}); 
auto f=[&](char a,char b){ if(a=='s'&&b=='r') return r; else if(a=='p'&&b=='s') return s; else if(a=='r'&&b=='p') return p; return 0; };
for(int i=0;i<n;i++){
for(int j=0;j<3;j++){
if(i<k){ dp[i][j]=f(t[i],c[j]); }
else {
for(int m=0;m<3;m++){
if(m==j) continue;
else dp[i][j]=max(dp[i][j],dp[i-k][m]+f(t[i],c[j])); 
}
}
}
}
ll ans=0;
vector<int> vis(n,0); 
for(int i=0;i<n;i++){
if(vis[i]) continue;
else {
int j=i;
while(j+k<n){  j+=k; vis[j]=1;  }
ans+=*max_element(dp[j].begin(),dp[j].end()); 
}
}
cout<<ans<<"\n"; 
return 0;
}

