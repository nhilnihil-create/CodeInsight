#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define pb push_back
#define es erase
#define in insert

#define pii pair<int, int>
#define ll long long
#define lb long double

#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

#define m_p(i, j) make_pair(i, j)
#define mem(a, x) memset(a, x, sizeof(a))
#define endl "\n"
#define all(x) x.begin(), x.end()

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b * c)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
    return 0;
}
