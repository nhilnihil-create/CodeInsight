#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<P>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main()
{
    string s;
    cin >> s;
    ll n = s.size();
    bool yes = true;
    
    rep(i, n)
    {
        if (i % 2 == 0)
        {
            if (!(s[i] == 'R' || s[i] == 'U' || s[i] == 'D'))
                yes = false;
        }
        if (i % 2 == 1)
        {
            if (!(s[i] == 'L' || s[i] == 'U' || s[i] == 'D'))
                yes = false;
        }
    }

    if (yes)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}