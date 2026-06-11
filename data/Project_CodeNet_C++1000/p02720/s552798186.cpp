#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    int k;
    cin >> k;
    vector<ll> lun;
    for (int i = 1; i < 10; i++) lun.push_back(i);
    int cnt = 0;
    while (lun.size() <= k) {
        ll p = lun[cnt] * 10;
        int q = lun[cnt] % 10;
        if (q == 0) {lun.push_back(p);lun.push_back(p+1);}
        else if (q == 9) {lun.push_back(p+8);lun.push_back(p+9);}
        else {
            for (int i = q-1; i <= q+1; i++) lun.push_back(p+i);
        }
        cnt++;
    }
    cout << lun[k-1] << endl;
    return 0;
}