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
  double N, Na;
  int X, ans;
  
  cin >> N;
  Na = N + 0.99;
  X = Na / 1.08;
  ans = X * 1.08;

  if(N == ans){
    cout << X << endl;
  }
  else{
    cout << ":(" << endl;
  }
}