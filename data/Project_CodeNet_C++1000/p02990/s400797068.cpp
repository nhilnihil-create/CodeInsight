#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define reps(i,n) for (int i=1;i<=(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#define rreps(i,n) for (int i=(n);i>0;i--)
#define all(v) (v).begin(),(v).end()
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>
template<class T> inline bool chmin(T &a, T b) {if (a>b) {a = b; return 1;} return 0;};
template<class T> inline bool chmax(T &a, T b) {if (a<b) {a = b; return 1;} return 0;};
typedef long long int ll;
const long long INF = 1LL << 60;


const long long MAX = 2010;
const long long MOD = 1000000007;
long long COM[MAX][MAX];

void COMinit(){
  for (int i=0;i<MAX;i++){
    COM[i][0] = 1;
    for (int j=1;j<=i;j++){
      COM[i][j] = (COM[i-1][j] + COM[i-1][j-1])%MOD;
    }
  }
}

int main(){
  int K, N; cin >> N >> K;
  COMinit();

  reps(i,K){
    ll ans = COM[N-K+1][i]*COM[K-1][i-1];
    ans %= MOD;
    cout << ans << endl;
  }


  // cout << fixed << setprecision(10);
  
  return 0;
}