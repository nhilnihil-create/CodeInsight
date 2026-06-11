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

    int n, sum = 0;
    cin >> n;

    if (n >= 400 && n <= 599)
        sum = 8;
    else if (n >= 600 && n <= 799)
        sum = 7;
    else if (n >= 800 && n <= 999)
        sum = 6;
    else if (n >= 1000 && n <= 1199)
        sum = 5;
    else if (n >= 1200 && n <= 1399)
        sum = 4;
    else if (n >= 1400 && n <= 1599)
        sum = 3;
    else if (n >= 1600 && n <= 1799)
        sum = 2;
    else if (n >= 1800 && n <= 1999)
        sum = 1;

    cout << sum << endl;

    return 0;
}
