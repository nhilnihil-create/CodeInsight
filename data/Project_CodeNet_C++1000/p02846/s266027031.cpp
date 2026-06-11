#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
int main() {
    ll t1, t2, a1, a2, b1, b2;
    cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
    ll taka = a1 * t1 + a2 * t2;
    ll aoki = b1 * t1 + b2 * t2;
    if (taka == aoki) {
        cout << "infinity" << endl;
        return 0;
    }
    if (((taka - aoki > 0) && (a1 > b1)) || ((taka - aoki < 0) && (a1 < b1))) {
        cout << 0 << endl;
        return 0;
    }
    ll first_dis = abs(a1 * t1 - b1 * t1);
    ll second_dis = abs(taka - aoki);
    //first_dis が second_disずつ縮まっていく
    ll count = 0;
    count += (first_dis / second_dis) * 2;
    if (first_dis % second_dis) {
        count++;
    }
    cout << count << endl;
    return 0;
}