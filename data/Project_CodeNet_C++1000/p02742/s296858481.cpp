#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repm(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a, b, c, i, j, k, l, m, n, ans, tmp, hoge;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> a >> b;

    if (a == 1 || b == 1)
        cout << 1 << endl;
    else
        cout << (a * b + 1) / 2 << endl;

    return 0;
}