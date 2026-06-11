#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  ll N;
  cin >> N;

  if(N%2==1){
    cout << 0 << endl;
    return 0;
  }
  
  N/=2;
  
  ll ret = 0;
  ll p = 5;
  while(p<=N){
    ret += N/p;
    p*=5;
  }

  cout << ret << endl;
  
  return 0;
}

