#include <bits/stdc++.h>
// clang-format off
using namespace std; using ll = int64_t; using ull = uint64_t; const ll INF = 9e18;
void print() { cout << endl; }
template<typename Head,typename... Tail> void print(Head head,Tail... tail){cout<<head;if(sizeof...(Tail)>0)cout<<" ";print(tail...);}
void print0() {}
template<typename Head,typename... Tail> void print0(Head head,Tail... tail){cout<<head;print0(tail...);}
// clang-format on
using pll = pair<ll, ll>;

ll dfs(ll left, ll right, vector<pll> &AA, vector<vector<ll>> &dp) {
    // 活発度が大きいものから順に、一番右または一番左のどちらかに移動させる
    if (left > right) {
        return 0;
    }
    if (dp[left][right] >= 0) {
        return dp[left][right];
    }
    ll i = AA.size() - right + left - 1;
    ll leftscore = AA[i].second * abs(AA[i].first - left) + dfs(left + 1, right, AA, dp);
    ll rightscore = AA[i].second * abs(AA[i].first - right) + dfs(left, right - 1, AA, dp);
    dp[left][right] = max(leftscore, rightscore);
    return dp[left][right];
}

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    vector<pll> AA(N);
    for (ll i = 0; i < N; i++) {
        cin >> A[i];
        AA[i] = {i, A[i]};
    }
    vector<vector<ll>> dp(N, vector<ll>(N, -1));
    sort(AA.begin(), AA.end(), [](pll a, pll b) { return a.second > b.second; });
    dfs(0, N - 1, AA, dp);

    ll maxscore = 0;
    for (auto row : dp) {
        for (auto score : row) {
            maxscore = max(maxscore, score);
        }
    }
    print(maxscore);
}
