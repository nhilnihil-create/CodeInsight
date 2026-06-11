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
  int A,B,C,K; cin >> A >> B >> C >> K;
  int ans = 0;
  REP(i,K){
    if(A > 0){ ans += 1; A--; continue;}
    if(B > 0){ B--; continue;}
    if(C > 0){ ans -= 1; C--; continue;}
  }
  cout << ans << endl;
}