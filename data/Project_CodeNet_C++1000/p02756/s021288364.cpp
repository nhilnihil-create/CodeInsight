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
  string S; cin >> S;
  ll Q; cin >> Q;
  int T,F;
  string C;
  bool revflag = false;
  REP(i,Q){
    cin >> T;
    if(T == 1) revflag = !revflag;
    if(T == 2){
      cin >> F >> C;
      if(F == 1) S.insert(revflag?S.size():0,C);
      if(F == 2) S.insert(revflag?0:S.size(),C);
  	}
  }
  if(revflag) reverse(ALL(S));
  cout << S << endl;
}