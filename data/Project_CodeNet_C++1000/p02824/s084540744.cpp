#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
#define PI 3.141592653589793



int main(){
  ll N, M, V, P; cin >> N >> M >> V >> P; ll a[N];
  rep(i, N){
    cin >> a[i];
  }
  sort(a, a+N); ll ok=1e18, ng=-1;
  while(abs(ok-ng)>1){
    ll mid = (ok+ng)/2; ll tmp=0;
    tmp+=(P-1)*M; ll lasti=-1;
    rep(i, N){
      if(a[i]<=mid && i<=N-P){
        tmp+=min(M, mid-a[i]); lasti=i;
      }
    }
    if(lasti<N-P){
      ng = mid; continue;
    }
    if(tmp<(V*M)){
      ng = mid; continue;
    }
    ok = mid; continue;
  }
  rep(i, N){
    if(a[i]>=ok-M){
      cout << N-i << endl; return 0;
    }
  }
}