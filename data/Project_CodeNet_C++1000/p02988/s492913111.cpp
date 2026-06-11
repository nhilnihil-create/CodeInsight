#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout << ((f) ? "Yes" : "No") << endl;
#define YORN(f) cout << ((f) ? "YES" : "NO") << endl;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, m, n) for (int i = m; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()
#define put(x) cout << x << endl;
#define println(x) cout << x << endl;
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];

    int c = 0;
    rep2(i, 1, n - 1)
    {
        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
            (p[i + 1] < p[i] && p[i] < p[i - 1]))
        {
            c++;
        }
    }
    put(c);
    return 0;
}