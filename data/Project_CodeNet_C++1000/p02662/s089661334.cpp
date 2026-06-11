#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <math.h>
#include <numeric>
#include <complex>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <bitset>
#include <functional>
#include <assert.h>
using ll=long long;
#define int ll
#define rng(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(i,b) rng(i,0,b)
#define gnr(i,a,b) for(int i=int(b)-1;i>=int(a);i--)
#define per(i,b) gnr(i,0,b)
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define fi first
#define se second
const int INF = 1e15;
const int MOD = 998244353;
using namespace std;

template<class T> using vc=vector<T>;
template<class T> using vvc=vc<vc<T>>;

using pi=pair<int,int>;
using vi=vc<int>;

template<class T>
inline bool chmax(T &a,T b){if(a<b){a=b;return true;}return false;}
template<class T>
inline bool chmin(T &a,T b){if(a>b){a=b;return true;}return false;}

int dp[3010][6010];
signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(20);

    int N,S; cin >> N >> S;
    int A[N]; 
    dp[0][0]=1;
    rep(i,N) cin >> A[i];
    rep(i,N) {
        per(j,S+1) {
            dp[i+1][j+A[i]]+=dp[i][j];
            dp[i+1][j+A[i]]%=MOD;
            dp[i+1][j]+=2*dp[i][j];
            dp[i+1][j]%=MOD;
        }
    }
    cout << dp[N][S] << endl;
}