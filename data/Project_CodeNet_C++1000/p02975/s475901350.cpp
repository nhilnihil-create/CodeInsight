#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    ll N;
    cin >> N;

    vector<ll> a(N);
    rep(i, N) cin >> a.at(i);

    ll a0 = a.at(0);
    ll a1;
    rep(i, N)
    {
        if (a.at(i) != a0)
        {
            a1 = a.at(i);
            break;
        }
    }

    ll a2 = a0 ^ a1;

    vector<ll> camels = {a0, a1, a2};

    bool result = true;
    for (int i = 0; i < N; i++)
    {
        auto it = find(a.begin(), a.end(), camels.at(i % 3));
        if (it != a.end())
        {
            a.erase(it);
        }
        else
        {
            result = false;
            break;
        }
    }

    cout << (result ? "Yes" : "No") << endl;

    return 0;
}