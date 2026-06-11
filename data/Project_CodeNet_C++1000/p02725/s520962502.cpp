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
  int K,N; cin >> K >> N;
  int tmp=0;
  vector<int> house(N); REP(i,N) cin >> house[i];
  REP(i,N){
    tmp = max(tmp,house[i+1] - house[i]);
  }
  tmp = max(tmp,house[0]+(K - house[N-1]));
  cout << K - tmp << endl;
}