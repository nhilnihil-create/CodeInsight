#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
vector<vector<int> > calcNext(const string &S) {
    int n = (int)S.size();
    vector<vector<int> > res(n+1, vector<int>(10, n));
    for (int i = n-1; i >= 0; --i) {
        for (int j = 0; j < 10; ++j) res[i][j] = res[i+1][j];
        res[i][S[i]-'0'] = i;
    }
    return res;
}
void add(long long &a, long long b) {
    a += b;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    string S;
    cin >> N >> S;
    vector<vector<int>> next = calcNext(S);
    vector<vector<ll>> dp(N+1, vector<ll>(4));
    dp[0][0] = 1;
    for (int i = 0; i < N; ++i) {
        for(int k = 0;k <= 2; k++){
            for (int j = 0; j < 10; ++j) {
                if (next[i][j] >= N) continue;
                add(dp[next[i][j] + 1][k+1], dp[i][k]);
            }
        }
    }
    ll res = 0;
    rep(i, N+1){
        add(res, dp[i][3]);
    }
    cout << res << endl;
}




