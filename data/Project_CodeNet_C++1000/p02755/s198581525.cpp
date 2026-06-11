#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define REP(i, n) for (LL i = 0; i < (LL)(n); i++)
#define REP2(i, n) for (LL i = 1; i <= (LL)(n); i++)
#define FOR(i, m, n) for (LL i = m; i < n; i++)
#define SORT(x) sort(x.begin(), x.end())
#define REVE(x) reverse(x.begin(), x.end())
#define ALL(x) (x).begin(), (x).end()
#define SUM(x) accumulate(x.begin(), x.end(),0LL)
#define vLL(v,n) vector<LL> v(n); REP(i,n)cin>>v[i];
#define vstr(v,n) vector<string> v(n); REP(i,n)REP(i,n)cin>>v[i];
LL INF = 1e9 + 1;
LL MOD = 1e9+7;
  LL zero,a,b,c,d,e,n,m,l,k,r,x,y,z,odd,ans=INF,ans2=0,h,w;
string s,S,t;
int main() {
ios_base::sync_with_stdio(false);
cin >> a >> b;
REP2(i,10000){
   if(floor(i*0.08)==a&&floor(i*0.1)==b){
       cout << i << endl;
       return 0;
   }
}
cout  << -1 <<endl;
return 0;
}