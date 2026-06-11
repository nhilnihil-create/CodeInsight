#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N,K; cin >> N >> K;
  vector<int> child(N);
  int tmp,d,ans=0;
  REP(i,K){
    cin >> d;
    REP(j,d){
      cin >> tmp;
      child[tmp-1]++;
    }
  }
  REP(i,N){
    if(child[i] == 0)
      ans++;
  }
  cout << ans << endl;
}