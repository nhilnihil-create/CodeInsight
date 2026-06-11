#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = n-1; i >= 0; i--)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) ((int)(x).size())
typedef long long ll;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<vector<int>>;
using VL = vector<ll>;
using VVL = vector<vector<ll>>;
using VP = vector<P>;
template<typename T> void view(T e){std::cout << e << std::endl;}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

const int inf = 1 << 30;
const ll INF = 1LL << 60;

int main(){
    int x;
    cin >> x;
    VI m = {100, 101, 102, 103, 104, 105};
    vector<vector<bool>> dp(7, vector<bool>(x+1, false));
    dp[0][0] = true;
    rep(i, sz(m)){
        int mon = m[i];
        rep(xi, x+1){
            dp[i+1][xi] = dp[i+1][xi] | dp[i][xi];
            if (xi - mon >= 0){
                dp[i+1][xi] = dp[i+1][xi] | dp[i+1][xi-mon];
            } 
        }
    }
    if (dp[sz(m)][x]) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}