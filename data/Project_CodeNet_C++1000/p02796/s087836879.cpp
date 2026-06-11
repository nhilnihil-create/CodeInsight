#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;
const ll LINF = 1001001001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<pair<ll, ll>> objs(n);
    for (int i = 0; i < n; i++)
    {
        ll x, l;
        cin >> x >> l;
        objs[i].first = x - l;
        objs[i].second = x + l;
    }
    sort(objs.begin(), objs.end());
    ll right = -LINF;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (objs[i].first >= right)
        {
            right = objs[i].second;
            ++ans;
        }
        else
        {
            if (objs[i].second < right)
            {
                right = objs[i].second;
            }
        }
    }
    cout << ans << endl;
    return 0;
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
};