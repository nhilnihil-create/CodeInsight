#include <algorithm>
#include <bits/stdc++.h>

#define ll long long
#define pi (acos(-1))
#define rep(i, n) for (unsigned long long i = 0; i < (unsigned long long)(n); ++i)
using namespace std;
std::vector<unsigned ll> genprimevec(const unsigned ll N);
int main()
{
    int n;
    cin >> n;
    vector<int> v(n), vv;
    rep(i, n) { cin >> v[i]; }
    vv = v;
    sort(vv.begin(), vv.end());
    rep(i, n)
    {
        if (v[i] == vv[n - 1]) { cout << vv[n - 2] << endl; }
        else
        {
            cout << vv[n - 1] << endl;
        }

    }
    return 0;
}
    /*author  https://qiita.com/drken/items/0c88a37eec520f82b788*/
    ll extgcd(ll a, ll b, ll & x, ll & y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        ll d = extgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }


    std::vector<unsigned ll> genprimevec(const unsigned ll N)
    {
        std::vector<bool> is_prime(N + 1);
        for (unsigned ll i = 0; i <= N; i++) { is_prime[i] = true; }
        std::vector<unsigned ll> P;
        for (unsigned ll i = 2; i <= N; i++)
        {
            if (is_prime[i])
            {
                for (unsigned ll j = 2 * i; j <= N; j += i) { is_prime[j] = false; }
                P.emplace_back(i);
            }
        }
        return P;
    }
