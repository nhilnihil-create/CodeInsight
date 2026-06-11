#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
using pint = pair<int,int>;
ll mod = 1000000007,mod2 = 998244353;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL<<60;
ll gcd(ll a,ll b){
    if(b == 0) return a;
    else return gcd(b,a%b);
}

bool is_prime[1000010];
int dp[100010];
int ana[100010];
int main() {
    int n,m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i){
        cin >> a[i];
        ana[a[i]] = 1;
    }
    dp[0] = 1;
    if(ana[1] != 1)dp[1] = 1;
    else dp[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if(!ana[i-2]){
            dp[i] += dp[i-2];
            dp[i] %= mod;
        }
        if(!ana[i-1]){
            dp[i] += dp[i-1];
            dp[i] %= mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}