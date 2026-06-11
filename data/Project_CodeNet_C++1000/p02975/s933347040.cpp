#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    ll xsum = 0;
    rep(i, n)
    {
        ll a;
        cin >> a;
        xsum = xsum ^ a;
    }
    if (xsum == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}