#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (ll)n; ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))
using namespace std;

//高々000-999の1000個

void solve(void)
{
    int n;
    string s;
    cin >> n >> s;
    vector<map<char, int>> v(10);
    int ans = 0;
    rep(i, 1000)
    {
        int x = i;
        vector<char> c(3);
        rep(j, 3) c[j] = x % 10 + '0', x /= 10;
        reverse(all(c));
        int tmp = 0;
        int l, m, r;
        l = 0;
        while (s[l] != c[0] && l < n)
            l++;
        m = l + 1;
        while (s[m] != c[1] && m < n)
            m++;
        r = m + 1;
        while (s[r] != c[2] && r < n)
            r++;
        if (r < n)
            ans++;
    }
    cout << ans << endl;
}

int main(void)
{
    solve();
}
