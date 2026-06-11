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
const ll mod=998244353 ;
#define PI 3.141592653589793



int main(){
  int N; cin >> N; ll a[N]; int pla = 0;
  rep(i, N){
    cin >> a[i]; if(a[i]>=0) pla++;
  }
  if(pla==0) pla=1;
  if(pla==N) pla=N-1;
  sort(a, a+N, greater<>());
  ll ans = 0;
  rep(i, pla){
    ans+=a[i];
  }
  for(int i=pla; i<N; i++){
    ans-=a[i];
  }
  cout << ans << endl;
  ll x = a[N-1];
  rep(i, pla-1){
    cout << x << " " << a[i] << endl;
    x-=a[i];
  }
  ll xx = a[pla-1];
  rep(i, N-pla-1){
    cout << xx << " " << a[pla+i] << endl;
    xx-=a[pla+i];
  }
  cout << xx << " " << x << endl;
}
