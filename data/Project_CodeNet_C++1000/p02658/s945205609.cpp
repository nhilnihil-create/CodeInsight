#include <bits/stdc++.h>
using namespace std;

// utility
#define ALL(a) (a).begin(), (a).end()
#define FOR(i, begin, end) for (int i = (begin); i < (end); i++)
#define REP(i, n) FOR(i, 0, n)
#define rer(i, l, u) for (int(i) = (int)(l); (i) <= (int)(u); ++(i))
#define reu(i, l, u) for (int(i) = (int)(l); (i) < (int)(u); ++(i))

#define Sort(v) sort(v.begin(), v.end())
#define Reverse(v) reverse(v.begin(), v.end())
#define Max(a, b) a = max(a, b)
#define Min(a, b) a = min(a, b)

#define YES() printf("YES\n")
#define NO() printf("NO\n")
#define isYES(x) printf("%s\n", (x) ? "YES" : "NO")
#define Yes() printf("Yes\n")
#define No() printf("No\n")
#define isYes(x) printf("%s\n", (x) ? "Yes" : "No")
#define F first
#define S second

char s[11];

signed main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<long long> a(n);
    REP(i, n)
    cin >> a[i];

    long long num = 1;

    REP(i, n)
    if (a[i] == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    REP(i, n)
    {

        if (a[i] <= 1000000000000000000 / num)
        {
            num *= a[i];
        }
        else
        {
            cout << "-1" << endl;
            return 0;
        }
    }
    cout << num << endl;
    return 0;
}
