#include <bits/stdc++.h>

#define ed cout << "\n";
#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define ll long long
#define ffor(i, a, b) for (ll i = (ll)(a); i < (ll)(b); ++i)
#define rep(i, n) ffor(i, 0, n)
#define All(obj) (obj).begin(), (obj).end()
#define INF ((ll)1e9 + 7)
#define c(a) cout << a << "\n";
using namespace std;
const int N = 100005;

int main()
{
    speed;
    cout << fixed << setprecision(6);
    /*start*/
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sum = 0;
    rep(i, n)
    {
        cin >> a[i];
        sum += a[i];
    }

    int count = 0;

    rep(i, n)
    {
        if (a[i] >= (double)sum / (4 * m))
            count++;
        if (count >= m)
            break;
    }
    string res = count == m ? "Yes" : "No";
    c(res);
}
