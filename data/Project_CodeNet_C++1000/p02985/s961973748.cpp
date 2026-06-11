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

vector<int> to[101010];
bool visited[101010] = {};
ll ans=1; int n, k;

const int MAX = 1000000;
const int MOD = 1000000007;

long long fac[MAX], finv[MAX], inv[MAX];

// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}


void DFS(int a, int p, int depth){
  int child = 0;
  visited[a] = true;
  for(auto o: to[a]){
    if(o==p) continue;
    if(visited[o]) continue;
    child++;
    DFS(o, a, depth+1);
  }
  if(depth==0) ans*=(COM(k-1, child)*fac[child]%mod);
  else ans*=(COM(k-2, child)*fac[child]%mod);
  ans%=mod;
}



int main(){
  cin >> n >> k;
  rep(i, n-1){
    int a, b; cin >> a >> b; a--; b--;
    to[a].push_back(b); to[b].push_back(a);
  }
  ans = k; COMinit();
  DFS(0, -1, 0);
  cout << ans << endl;
}