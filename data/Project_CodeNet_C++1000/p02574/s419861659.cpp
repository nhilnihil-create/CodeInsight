#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define pb push_back
#define es erase
#define in insert

#define pii pair<ll, ll>
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

const ll mod = 1e9 + 7;
const ll maxn = 1e7 + 7;

int n, nums[maxn], t;

void split(int x)
{
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)
            nums[i]++;
        while (x % i == 0)
            x /= i;
    }
    if (x != 1)
        nums[x]++;
}
int gcd(int a, int b)
{
    return __gcd(a, b);
}
int main()
{
    cin >> n;
    int gc = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        split(t);
        if (i == 1)
            gc = t;
        else
            gc = gcd(gc, t);
    }
    if (*max_element(nums + 2, nums + maxn - 10) < 2) {
        cout << "pairwise coprime" << endl;
    } else {
        if (gc == 1) {
            cout << "setwise coprime" << endl;
        } else {
            cout << "not coprime" << endl;
        }
    }
}
