#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define all(x)(x).begin(), (x).end() // 昇順ソート
#define rall(v)(v).rbegin(), (v).rend() // 降順ソート
#define INF 1LL << 60
typedef long long int LL;
typedef long long int ll;
#define pll pair < ll, ll >
#define F first
#define S second
const int MOD = 1000000007;
template < class T > bool chmax(T & a,const T & b) { if (a < b) { a = b; return true; } return false; }
template < class T > bool chmin(T & a,const T & b) { if (a > b) { a = b; return true; } return false; }
// 任意のlogは　対数の底の変換を使う    log(N) / log(任意の底)

int main() {
    string S;cin >> S;   
    int sz = S.size();
    int mod = 2019;
    vector<LL> ten_dp(sz + 4);
    ten_dp[0] = 1 % mod;
    for(int i = 1;i <= sz;i++){
        ten_dp[i] = ((ten_dp[i-1]) * 10) % mod;
    }



    vector<LL> dp(sz+4);
    dp[sz-1] = (S[sz-1] - '0') * ten_dp[0];
    for(int i = 1;i < sz;i++){
        int num = S[sz-1-i] - '0';
        dp[sz-1-i] = (((num * ten_dp[i]) % mod) + dp[sz-i]) % mod;
    }

    map<int,int> m;
    rep(i,sz){
        m[dp[i]]++;
    }

    LL ans = 0;

    for(auto t : m){
        ans += (t.S*(t.S - 1)/2);
        if(t.F == 0)ans += t.S;
    }

    cout << ans << endl;
}