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
  int A,B; cin >> A >> B;
  REP(i,1010){
    if(int(i * 0.08) == A && int(i * 0.1) ==B){
      cout << i << endl;
      return 0;
    }
  }
  cout << "-1" << endl;
}