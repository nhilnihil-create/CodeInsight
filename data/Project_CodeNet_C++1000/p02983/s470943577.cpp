#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    ll L, R;
    cin >> L >> R;
    ll modL = L%2019;
    ll modR = R%2019;

    if(R - L > 2019 - modL) {
        cout << 0 << endl;
        return 0;
    }
    ll minimum = 2020;
    for(ll i = L; i < R; i++){
        for(ll j = i+1; j <= R; j++){
            ll val = ( (i % 2019) * (j%2019) )% 2019;
            if(val < minimum) minimum = val;
            if(val == 0) {
                minimum = 0;
                break;
            }
        }
    }
    
    cout << minimum << endl;
    return 0;
}
