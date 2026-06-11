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
  int N,M; cin >> N >> M;
  vector<int> data(M); REP(i,M) cin >> data.at(i);
  
  REP(i,M){
    N -= data.at(i);
  }
  if(N < 0)
    cout << "-1" <<endl;
  else
    cout << N << endl;
}