#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<int,int>;

int main()
{
  ll N,M;
  cin >> N >> M;
  vector<int> A(N);
  priority_queue<ll> pq;
  REP(i, N){
    cin >> A[i];
    pq.push(A[i]);
  }

  REP(i,M){
    ll x = pq.top();
    pq.pop();
    x/=2;
    pq.push(x);
  }

  ll sum = 0;
  while(!pq.empty()){
    sum+=pq.top();
    pq.pop();
  }

  cout << sum << endl;
}