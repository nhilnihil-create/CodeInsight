#include <bits/stdc++.h>

typedef long long ll;

#define SIZE_OF_ARRAY(array) (sizeof(array) / sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define AA(i) cout << i << endl;
#define AS(i) cout << i << " ";

const int INF = 1000000007;
const double PI = 3.14159;

using namespace std;


vector<ll> enum_divisors(ll N)
{
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (N / i != i)
                res.push_back(N / i);
        }
    }
    // 小さい順に並び替える
    sort(res.begin(), res.end());
    return res;
}

vector<pair<ll, ll>> prime_factorize(ll N)
{
    vector<pair<ll, ll>> res;
    for (ll a = 2; a * a <= N; ++a)
    {
        if (N % a != 0)
            continue;
        ll ex = 0;

        while (N % a == 0)
        {
            ++ex;
            N /= a;
        }
        res.push_back({a, ex});
    }
    if (N != 1)
        res.push_back({N, 1});
    return res;
}

int main() {

    ll n;
    cin >> n;

    ll ans = 0;

    vector<ll> ed = enum_divisors(n);
    rep(i, ed.size()) {
        if (prime_factorize(ed[i]).size() == 1 && n % ed[i] == 0) {
            n /= ed[i];
            ans++;
        }
    }

    AA(ans);
}