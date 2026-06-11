#include<iostream>
#include <cstring>
#include<string>
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
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;



int main(){
  ll N; cin >> N; N++; ll a[N];
  rep(i, N){
    cin >> a[i];
  }
  ll tmp=0, ans=0;
  ll need[N] = {}; need[0] = 1;
  //コーナーケース
  if(a[0]!=0){
    if(N==1&&a[0]==1){cout << 1 << endl; return 0;}
    else {cout << -1 << endl; return 0;}
  }
  if(N==1){ cout << -1 << endl; return 0;}
  //上から決める、need[i]は深さiの上限
  rep(i, N-1){
    need[i+1] = (need[i]-a[i])*2;
    need[i+1] = min(need[i+1], longinf);
    if(need[i+1]<a[i+1]){
      cout << -1 << endl; return 0;
    }
  }
  ll v[N];
  for(int i=N-1; i>=0; i--){
    tmp+=a[i];
    v[i] = min(need[i], tmp);
    tmp=v[i];
  }
  rep(i, N){
    ans+=v[i];
  }
  cout << ans << endl;
}
