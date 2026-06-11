#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PI 3.14159265359

int main() {
    ll x, k ,d, ans;
    cin >> x >> k >> d;
    x = abs(x);
    if(x/d >= k){
        ans = x - d*k;
    }else{
        k -= x/d;
        x = x - d*(x/d);
        if(k%2==0)ans = x;
        else ans = abs(x - d);
    }
    cout << ans << endl;
    return 0;
}