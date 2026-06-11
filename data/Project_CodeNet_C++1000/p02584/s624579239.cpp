#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll x, k, d, ans;
    cin >> x >> k >> d;
    x = abs(x);
    if(x/d >= k){
            ans = x - k * d;
    } else {
            k -= x / d;
            if(k % 2 == 0){
                    ans = x - d * (x / d);
            } else {
                    ans = d * (x / d + 1) - x;
            }
    }
    cout << ans << endl;
    return 0;
}
