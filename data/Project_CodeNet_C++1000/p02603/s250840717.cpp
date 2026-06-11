#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n, a[87] = {0}; cin >> n;
    for(int i=0; i<n; i++) cin >> a[i];
    ll money = 1000;
    ll cnt = 0;
    for(int i=0; i<n; i++) {
        if(a[i] < a[i + 1]) {
            ll num = money / a[i];
            cnt += num;
            money -= a[i] * num;
        }
        else {
            money += cnt * a[i];
            cnt = 0;
        }
    }
    cout << money << endl;
}