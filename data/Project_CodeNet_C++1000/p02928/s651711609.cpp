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
    ll n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        --a[i];
    }
    ll after_min = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                ++after_min;
            }
        }
    }
    ans = (after_min * k) % MOD;
    vector<int> nums(2000);
    for (auto num : a)
    {
        ++nums[num];
    }
    reverse(nums.begin(), nums.end());
    ll cnt = 0;
    ll mins = 0;
    for (int i = 0; i < 2000; i++)
    {
        mins = (mins + nums[i] * cnt) % MOD;
        cnt += nums[i];
    }
    ll sig = (k * (k - 1) / 2) % MOD;
    ans = (ans + (mins * sig) % MOD) % MOD;
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