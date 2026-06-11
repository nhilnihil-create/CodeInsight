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

int main(){
  int N, M; cin >> N >> M;
  int S[N], T[M];
  rep(i, N){
    cin >> S[i];
  }
  rep(i, M){
    cin >> T[i];
  }
  ll dp[N+1][M+1] = {}; ll cum[N+1][M+1] = {};
  rep(i, N){
    rep(j, M){
      if(S[i]==T[j]) dp[i+1][j+1]=(cum[i][j]+1)%mod;
      else dp[i+1][j+1] = 0;
      cum[i+1][j+1]+=(((cum[i][j+1]+cum[i+1][j])%mod-cum[i][j]+mod)%mod+dp[i+1][j+1])%mod;
      cum[i+1][j+1]%=mod;
    }
  }
  //cout << cum[1][2] << " " << cum[2][1] << " " << cum[1][1] << endl;
  cout << (cum[N][M]+1)%mod << endl;
}
