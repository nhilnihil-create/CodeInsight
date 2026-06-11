#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
typedef long long ll;
typedef unsigned long long ull;


int main(){
  int N, M;
  cin >> N >> M;
  string S;
  cin >> S;

  int now = N;
  vector<int> ret;
  while(now > 0){
    int mn = now;
    REP(i,1,M+1){
      if(now-i < 0) continue;
      if(S[now-i] == '0'){
        mn = now-i;
      }
    }
    if(mn == now){
      ret.clear();
      break;
    }
    ret.push_back(now - mn);
    now = mn;
  }

  if(ret.size() == 0){
    cout << -1 << endl;
  }else{
    reverse(ALLOF(ret));
    rep(i,ret.size()){
      if(i>0) cout << " ";
      cout << ret[i];
    }
    cout << endl;
  }
  
  return 0;
}
