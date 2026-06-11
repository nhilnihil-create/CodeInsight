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
  string S1,S2;
  int N = S.size();
  bool flag1 = true;
  bool flag2 = true;
  REP(i,(N-1)/2){
    if(S[i] != S[(N-2)/2 - i]) 
      flag1 = false;
  }
  FOR(i,(N+2)/2,N){
  	if(S[i] != S[N-1-i])
      flag2 =false;
  }
  if(flag1 && flag2)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}