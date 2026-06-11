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

    int n, m;
    cin >> n >> m;
    
    multiset<int> mu;

    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        mu.insert(a);
    }

    ll ans = 0LL;
    for(int i = m; i > 0; --i)
    {
        if(mu.empty())
            break;
        //cout << sz(mu) << '\n';
        int naj = *mu.rbegin();
        //cout << naj << '\n';
        mu.erase(prev(mu.end()));
        naj >>= 1;
        //cout << naj << '\n';
        if(naj)
            mu.insert(naj);
    }
    //cout << mu.size() << '\n';

    for(auto z : mu)
    {
        //cout << z << '\n';
        ans += 1LL * z;
    }
    cout << ans << '\n';
}
