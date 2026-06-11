#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define prl(x) cout<<(x)<<endl
int main(void){string s,t;map<char,vl>c;cin>>s>>t;ll n=s.length(),cur=0;rep(i,n)c[s[i]].push_back(i);for(char a:t){vl& v=c[a];if(!v.size()){prl(-1);return 0;}auto it=lower_bound(v.begin(),v.end(),cur%n);(cur=cur/n*n+1)+=it==v.end()?*(v.begin())+n:*it;}prl(cur);return 0;}