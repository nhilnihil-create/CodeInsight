#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main () {
    ll l, r;
    cin >> l >> r;
    if(r - l >= 2019){
        cout << 0 << endl;
        return 0;
    }
    l %= 2019;
    r %= 2019;
    int Min = 2019;
    for(int i = min(l, r); i < max(l, r); i++) {
        for(int j = i + 1; j <= max(l, r); j++) Min = min((i * j) % 2019, Min);
    }
    cout << Min << endl;
}
