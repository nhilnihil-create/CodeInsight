#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);++i)
const int M=1e9+7;
int main(void){string s,t;cin>>s>>t;long long a=0,c=0,n=s.length(),m=t.length(),x;vector<set<int>>v(26);rep(i,26)v[i].insert(M);rep(i,n)v[s[i]-'a'].insert(i+1);rep(i,m){x=t[i]-'a';c=*v[x].upper_bound(c);if(c==M)++a,c=*v[x].begin();if(c==M){cout<<-1;return 0;}}cout<<a*n+c;return 0;}
