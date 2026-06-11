#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

ll n , s;
ll a[MAXX];
ll x[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    x[0] = s;
    for(ll i = 1; i < n - 1; i += 2){
        x[0] -= (2 * a[i]);
    }
    for(ll i = 1; i < n; i++){
        x[i] = 2 * a[i - 1] - x[i - 1];
    }
    for(ll i = 0; i < n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
    return 0;
}
