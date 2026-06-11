#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll, ll> p_ll;
typedef vector<pair<ll, ll>> vec_p; //vector<pair<ll, ll>> pairs(n) ,pairs.at(i) = make_pair(i*i, i)

#define ture ture
#define flase false
#define falg flag

#define REP(i, x) for (ll i = 0; i < (ll)(x); i++)
#define REPS(i, x) for (ll i = 1; i <= (ll)(x); i++)
#define RREP(i, x) for (ll i = ((ll)(x)-1); i >= 0; i--)
#define RREPS(i, x) for (ll i = ((ll)(x)); i > 0; i--)
#define all(x) (x).begin(), (x).end()

const ll MOD = pow(10, 9) + 7;
const ll LLINF = pow(2, 61) - 1;//llの最大9*10^18
const int INF = pow(2, 30) - 1;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

vector<pair<long long, long long>> prime_factorize(long long N)
{
    vector<pair<long long, long long>> res;
    for (long long a = 2; a * a <= N; ++a)
    {
        if (N % a != 0)
            continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0)
        {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1)
        res.push_back({N, 1});
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll A,B;
    string S;
    cin >> A>>B;

    ll C = gcd(A, B);

    const auto &res = prime_factorize(C);

    cout << res.size() + 1 << endl;

}
