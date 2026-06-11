#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<int,int> P;

template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}

ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}

int dp[3030][3030]; //dp[i][j] = i番目までの料理をj分以内で食べる時の満足度の最大値

int main() {
    int N,T;
    cin >> N >> T;
    vector<P> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i).first >> vec.at(i).second;
    }
    sort(vec.begin(),vec.end());
    for(int i = 0;i < 3030;i++) {
        dp[0][i] = 0;
    }
    for(int i = 0;i < N;i++) {
        for(int j = 0;j <= T - 1;j++) {
            if(vec.at(i).first > j) {
                dp[i + 1][j] = dp[i][j];
            }
            else {
                dp[i + 1][j] = max(dp[i][j],dp[i][j - vec.at(i).first] + vec.at(i).second);
            }
        }
    }
    int ret = 0;
    for(int i = 0;i < N;i++) {
        ret = max(ret,dp[i][T - 1] + vec.at(i).second);
    }
    cout << ret << endl;
}