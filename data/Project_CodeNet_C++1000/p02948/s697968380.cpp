#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define cvector vector<char>
#define svector vector<string>
#define lque queue<ll>
#define lpque priority_queue<ll>
#define dlpque priority_queue<ll,lvector,greater<ll>>
#define P pair<ll,ll>
#define ALL(a) a.begin(),a.end()
#define RALL(a) a.rbegin(),a.rend()
#define rep(i,n) for(ll i=0; i<n; ++i)
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,m,ans=0,a,b;cin>>n>>m;
  vector<lvector> jobs(m);
  rep(i,n) {
    cin>>a>>b;
    if(a>m) continue;
    jobs[m-a].emplace_back(b);
  }
  lpque que;
  for(ll i=m-1;i>-1;--i) {
    for(ll job:jobs[i]) que.push(job);
    if(que.size()) {ans+=que.top();que.pop();}
  }
  print(ans);
  return 0;
}