#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)
#define debug(x) cerr << #x << ": " << x << '\n'

int main()
{
    ll N;
    cin >> N;
    vector<string> S(N);
    vector<ll> t(N);
    string X;
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i] >> t[i];
    }
    cin >> X;
    bool add = false;
    ll ans = 0;

    for (int i = 0; i < N; ++i)
    {
        if (add)
        {
            ans += t[i];
        }
        if (S[i] == X)
        {
            add = true;
        }
    }
    cout << ans << endl;
}
