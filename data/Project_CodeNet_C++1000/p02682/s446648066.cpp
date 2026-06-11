#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int ll

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define For(i, a) for (int i=0; i<a; i++)
#define FORR(i,a,b) for (int i = a; i >= b; i--)
#define Forr(i,a) for (int i = a; i >= 0; i--)

#define deb(...) cerr << "[" << #__VA_ARGS__ << "] : [", DBG(__VA_ARGS__)
void DBG() { cerr << "]\n";}
template<typename T, typename ...Args> void DBG(T first, Args... args)
{cerr << first; if(sizeof...(args))cerr<<", "; DBG(args...); }

void solve(){
  int a,b,c,k; cin >> a >> b >> c >> k;
  int ans=min(a,k);
  int picked=min(a,k);
  ans += min(k-ans,b*0);
  picked += min(k-picked,b);
  ans += min(k-picked,c)*(-1);
  cout << ans << "\n";
}


int32_t main(){
  ios_base:: sync_with_stdio(false);
  cin.tie(0);
  int t=1;
  for(int tt=1;tt<=t;tt++){
    solve();
  }
}