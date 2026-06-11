#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll const con = 1000000000000000000;

int main() {
    int n; cin >> n;
    vector<ull> vec(n);
    ll ans = 1;
    bool zero = true;
    for (int i = 0; i < n; i++) {
        cin >> vec.at(i);
        if (vec.at(i) == 0) zero = false;
    }

    if(zero) {
        for (int i = 0; i < n; i++) {
            if(vec.at(i) <= con / ans) ans *= vec.at(i);
            else {
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
    else cout << '0' << endl;
}