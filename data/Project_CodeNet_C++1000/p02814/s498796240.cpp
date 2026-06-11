#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

ll __lcm(ll a, ll b)
{
    return a / __gcd(a, b) * b;
}

ll lcm(vector<ll> vec)
{
    ll ret = vec[0];
    for (int i = 0; i < vec.size(); i++)
    {
        ret = __lcm(ret, vec[i]);
    }
    return ret;
}

ll solve(int N, ll M, vector<ll> &a)
{
    bool same = true;
    while (a[0] % 2 == 0)
    {
        for (int i = 0; i < N; ++i)
        {
            if (a[i] % 2 != 0)
            {
                return 0;
            }
            a[i] /= 2;
        }
        M /= 2;
    }
    for (int i = 0; i < N; ++i)
    {
        if (a[i] % 2 == 0)
        {
            return 0;
        }
    }

    // lcm
    ll l = lcm(a);
    return (M / l + 1) / 2;
}

int main()
{
    int N;
    ll M;
    cin >> N >> M;
    vector<ll> a(N);

    // あらかじめaは１回2で割っておく
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        a[i] /= 2;
    }
    cout << solve(N, M, a) << endl;
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << ' ';
        cout << v[i];
    }
    cout << endl;
}