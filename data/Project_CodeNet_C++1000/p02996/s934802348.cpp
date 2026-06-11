#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) < (b) ? (b) : (a))

const long long INF = 1LL << 60;
typedef long long ll;
const long long MOD = 1000000000 + 7;

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> v;
    ll a, b;
    rep(i, n)
    {
        cin >> a >> b;
        v.push_back({b, a});
    }
    ll time = 0;
    sort(v.begin(), v.end());
    rep(i, n)
    {
        time += v[i].second;
        if (time > v[i].first)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}