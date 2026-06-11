#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(),(x).end()
using ll = long long;
using ld = long double;
#define vl vector<long long>
#define vvl vector<vector<long long>>
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
using pll = pair<long long,long long>;
#define cY cout<<"Yes"<<endl
#define cN cout<<"No"<<endl
const long long INF = 1LL << 60;
const long long MOD = 1000000007;
const long double pi = (acos(-1));
#define pb push_back
#define vs vector<string>

//最大最小の入れ替え
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

//約数列挙
vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}
//コンビネーション
ll nCr(ll n, ll r) {
    ll ans = 1;
    for (ll i = n; i > n - r; --i) {
        ans = ans*i;
    }
    for (ll i = 1 ; i < r + 1; ++i) {
        ans = ans / i;
    }
    return ans;
}
//素因数分解
map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= n; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

//切り上げの割り算は(a + b - 1) / bでできる

//ここから
int main(){
    ll H,W;
    cin>>H>>W;
    vector<vector<char>> grid(W,vector<char>(H));
    rep(i,H)rep(j,W)cin>>grid[j][i];
    vvl dp(W,vl(H,INF));
    if(grid[0][0]=='#') dp[0][0]=1;
    else dp[0][0]=0;
    rep(i,H){
        rep(j,W){
            if(j!=W-1){
                if(grid[j][i]=='.'&&grid[j+1][i]=='#'){
                    chmin(dp[j+1][i],dp[j][i]+1);
                }else{
                    chmin(dp[j+1][i],dp[j][i]);
                }
            }
            if(i!=H-1){
                if(grid[j][i]=='.'&&grid[j][i+1]=='#'){
                    chmin(dp[j][i+1],dp[j][i]+1);
                }else{
                    chmin(dp[j][i+1],dp[j][i]);
                }
            }
        }
    }
    cout<<dp[W-1][H-1]<<endl;
}