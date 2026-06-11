#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll n, a, b;
    cin >> n >> a >> b;
    if((b - a) % 2 == 0){
        cout << (b - a) / 2 << endl;
    } else {
        ll cnt1 = (a - 1) + 1 + (b - a - 1) / 2;
        ll cnt2 = (n - b) + 1 + (b - a - 1) / 2;
        cout << min(cnt1, cnt2) << endl;
    }
    return 0;
}