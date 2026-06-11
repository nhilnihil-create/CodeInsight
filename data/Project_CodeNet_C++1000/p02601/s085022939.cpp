#include <bits/stdc++.h>

using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(NULL);                \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define Debug(x) cout << #x " = " << (x) << endl
#define SORT(a) sort(a.begin(), a.end())
#define SORTR(a) sort(a.rbegin(), a.rend())
#define mod 1000000007
#define pi 3.141592653589793238
#define ll long long int
#define ull unsigned long long
#define be begin()
#define en end()
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define FORI(i, a, b) for (int i = a; i >= b; i--)

typedef vector<int> VI;
typedef vector<ll> VL;
typedef pair<int, int> PI;
typedef pair<ll, ll> PL;
typedef vector<PI> VPI;

int main()
{
    IOS;

    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if (a < b && b < c)
    {
        cout << "Yes" << endl;
    }
    else
    {
        while (k > 0 && a >= b)
        {
            k--;
            b *= 2;
        }

        while (k > 0 && b >= c)
        {
            k--;
            c *= 2;
        }

        if (a < b && b < c)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
