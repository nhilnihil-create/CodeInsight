#include <bits/stdc++.h>
typedef long long ll;

#define rep(i, a, n) for (ll i = a; i < (ll)n; ++i)
#define INF 10e12
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

bool is_prime(ll N)
{
    if (N < 2)
        return false;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return false;
    }
    return true;
}
vector<pair<ll, ll>> soinsubunkai(ll N)
{
    vector<pair<ll, ll>> tmp;
    ll num = N;
    for (ll i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
        {
            ll j = N / i;
            if (is_prime(i))
            {
                ll a = 1;
                while (num % i == 0)
                {
                    a++;
                    num /= i;
                }
                tmp.push_back({i, a});
            }
            if (is_prime(j))
            {
                ll a = 1;
                while (num % j == 0)
                {
                    a++;
                    num /= j;
                }
                tmp.push_back({j, a});
            }
        }
    }
    return tmp;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll a, b;
    cin >> a >> b;
    vector<pair<ll, ll>> v = soinsubunkai(__gcd(a, b));
    if (v.size() == 0 && __gcd(a, b) != 1)
        v.push_back({__gcd(a, b), 1});
    cout << v.size() + 1 << endl;
}