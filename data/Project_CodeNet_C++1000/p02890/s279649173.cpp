#include<iostream>
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
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
  int N; cin >> N; int cnt[N+1] = {};
  rep(i, N){
    int a; cin >> a; cnt[a]++;
  }
  sort(cnt, cnt+N+1, greater<>()); int kazu[N+1] = {};
  rep(i, N+1){
    kazu[cnt[i]]++;
  }
  int cum[N+2] = {};
  for(int i=N; i>=0; i--){
    cum[i] = cum[i+1]+kazu[i];
  }
  int all=N; int ma = cnt[0];
  for(int i=1; i<=N; i++){
    while(ma>all/i){
      all-=cum[ma]; ma--; 
    }
    cout << all/i << endl;
  }  
}