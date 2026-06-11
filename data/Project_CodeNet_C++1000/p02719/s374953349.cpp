#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll n, k, ans;
    cin >> n >> k;
    n = n % k;
    while(true){
        ans = n;
        n = abs(n-k);
        if(ans < n) break;
    }
    cout << ans << endl;
    return 0;
}
