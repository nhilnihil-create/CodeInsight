#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

ll n;

int main()
{
    _FastIO;
    cin >> n;
    if(n % 2){
        cout << "0" << endl;
        return 0;
    }
    ll k = 1;
    ll ans = 0;
    while(k <= n){
        k *= 5;
        ll x = n / k;
        x /= 2;
        ans += x;
    }
    cout << ans << endl;
    return 0;
}
