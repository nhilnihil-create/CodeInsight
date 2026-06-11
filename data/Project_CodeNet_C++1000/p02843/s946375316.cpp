#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll x;
    cin >> x;
    ll ma = x / 100;
    ll mi = x / 105;
    for (int i = mi; i <= ma; i++)
    {
        ll tmp = x - 100 * i;
        if (0 <= tmp && tmp <= 5 * i)
        {
            cout << 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}