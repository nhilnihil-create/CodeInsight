#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x;
    cin >> x;

    long long k = 100;
    long long ans = 1;
    while(1) {
        k += (k/100);
        if (k >= x) {
            cout << ans << endl;
            break;
        }
        ans++;
    }
}