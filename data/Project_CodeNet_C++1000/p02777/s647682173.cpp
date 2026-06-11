#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  string S, T;
  cin >> S >> T;
  int A, B;
  cin >> A >> B;
  string U;
  cin >> U;

  if(S == U) A--;
  if(T == U) B--;

  cout << A << " " << B << endl;
  
  return 0;
}

