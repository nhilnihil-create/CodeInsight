#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(c) (c).begin(), (c).end()
#define pb push_back
#define eb emplace_back
const long long INF = 1LL<<60; // 仮想的な無限大の値;
using namespace std;
using ll = long long;
using P  = pair<int, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
vector<pair<long long, long long> > prime_factorize(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
int main()
{
    ll N;
    cin >> N;
    auto X = prime_factorize(N);
    // int MAX = N;24
    // vector<int> is_prime(MAX, 1);
    // is_prime[0] = 0, is_prime[1] = 0;
    // for (int i = 2; i*i < MAX; ++i) {
    //     if (!is_prime[i]) continue;
    //     for (int j = i*2; j < MAX; j += i) is_prime[j] = 0;
    // }
    ll ans = 0;
    int max = X.size();
    //cout << max << endl;
    rep(i, X.size())
    {
        int p = 1;
        for(int j = 0 ; j < X[i].second; j+=p)
        {
            ans++;
            p++;
        }
    }
    cout << ans << endl;
    return 0;
}