#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MOD 1000000007

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define RFOR(i, a, b) for (int i = (b)-1; i >= (a); i--)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep1(i, n) for (int i = 1; i < (n); i++)
#define rrep(i, n) for (int i = (n)-1; i >= 0; i--)
#define all(i) (i).begin(), (i).end()
#define rall(i) (i).begin(), (i).end(), greater<int>()

#define elif else if
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define fst first
#define sec second
template <typename T>
void print(T x)
{
    std::cout << x << '\n';
}

//typedef long long ll;

signed main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n)
    {
        cin >> a[i];
    }

    int c = min(k, 100ll);

    rep(i, c)
    {
        vector<int> b(n, 0);
        rep(j, n)
        {
            int l = max(0ll, j - a[j]);
            int r = min(n - 1, j + a[j]);
            b[l]++;
            if (r + 1 < n)
                b[r + 1]--;
        }
        rep(j, n - 1)
        {
            b[j + 1] += b[j];
        }
        rep(j, n)
        {
            a[j] = b[j];
        }
    }

    rep(i, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
