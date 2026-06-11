#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
const int INF = 1001001001;
const int MOD = 1000000007;

template <typename T>
void print(const T &v);

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n)
    {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n % 2 == 1)
    {
        // A, Bそれぞれの中央値を求める
        int left = a[n / 2];
        int right = b[n / 2];
        cout << right - left + 1 << endl;
        return 0;
    }
    else
    {
        int left = a[n / 2 - 1] + a[n / 2];
        int right = b[n / 2 - 1] + b[n / 2];
        cout << right - left + 1 << endl;
        return 0;
    }
}

// Use For Debug
template <typename T>
void print(T const &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (i)
            cout << " ";
        cout << v[i];
    }
    cout << endl;
}
