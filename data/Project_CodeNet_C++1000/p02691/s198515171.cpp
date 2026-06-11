#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef long long ll;
typedef long double ld;

#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()
#define fi first
#define se second

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vi v(n);

    for(auto &z : v)
        cin >> z;

    map<ll, ll> m;
    ll ans = 0LL;

    for(int i = 0; i < n; ++i)
    {
        ll razlika = i + 1LL - v[i];
        ans += m[razlika];
        ++m[v[i]+i+1];
    }

    //for(auto [key, value] : m)
    //{
        //cout << key << ' ' << value << '\n';
    //}

    cout << ans << '\n';

    return 0;
}

