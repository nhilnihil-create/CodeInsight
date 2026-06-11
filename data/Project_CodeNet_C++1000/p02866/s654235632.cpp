#include <bits/stdc++.h>

#include <algorithm>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
using ll = long long;


int main() {
    int n;
    cin >> n;
    V<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    ll ans = 1;
    if (v[0] != 0) ans = 0;
    sort(ALL(v));
    if (2 < n && v[1] == 0) ans = 0;

    ll cnt = 1, p = 1;
    for(int i = 1; i < n; i++){
        if(v[i - 1] == v[i]) cnt++;
        else if(v[i - 1] + 1 == v[i]){
            p = cnt;
            cnt = 1;
        }else{
            ans = 0;
        }
        ans *= p;
        ans %= 998244353;
    }
    cout << ans << endl;

    return 0;
}
