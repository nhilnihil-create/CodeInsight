#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 2005

ll n , k;
ll c[MAXX][MAXX];

int main()
{
    _FastIO;
    cin >> n >> k;
    for(ll i = 0; i < 2002; i++){
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for(ll i = 1; i < 2002; i++){
        for(ll j = 1; j < i; j++){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] %= 1000000007;
        }
        }
        for(ll i = 1; i <= k; i++){
            ll ans = c[n - k + 1][i];
            ans *= c[k - 1][i - 1];
            ans %= 1000000007;
            cout << ans << endl;
        }
    return 0;
}
