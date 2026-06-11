#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> a(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    int k;
    cin >> k;
    while (k && a[2] <= a[1] || a[1] <= a[0]) {
        if (a[1] <= a[0]) {
            a[1] *= 2;
        } else {
            a[2] *= 2;
        }
        k--;
    }
    if (a[2] > a[1] && a[1] > a[0]) {
        cout << "Yes" << endl;
    } else {
        cout << "No";
    }
}