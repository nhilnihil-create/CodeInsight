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
    vector<ll> as(n);
    for (int i = 0; i < n; i++)
    {
        cin >> as[i];
    }
    as.push_back(as[0]);
    ll left = -1;
    ll right = 1000000001;
    while (right - left > 1)
    {
        ll mid = (left + right) / 2;
        ll x = mid;
        bool flag = true;
        vector<ll> ans;
        for (int i = 0; i < n; i++)
        {
            ans.push_back(x * 2);
            x = as[i] - x;
        }
        if (mid == x)
        {
            print(ans);
            return 0;
        }
        else if (mid < x)
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }
    cout << "error" << endl;
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