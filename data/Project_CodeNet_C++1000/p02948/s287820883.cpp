#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
using P = pair<int,int>;
  
int main()
{
  ll N,M;
  cin >> N >> M;
  vector<P> A(N);
  REP(i,N) cin >> A[i].first >> A[i].second;
  

  vector<vector<ll>> vec(M,vector<ll> ());
  REP(i,N){
    if(M-A[i].first>=0){
      vec[M-A[i].first].push_back(A[i].second);
    }
  }
  priority_queue<int> pq;
  ll ans = 0;
  REPR(i,M-1){
    REP(j,vec[i].size()){
      pq.push(vec[i][j]);
    }
    if(pq.size()!=0){
      ans+=pq.top();
      pq.pop();
    }
  }

  cout << ans << endl;
}