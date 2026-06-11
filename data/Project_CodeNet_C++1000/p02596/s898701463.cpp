#include <bits/stdc++.h>
using namespace std;

int main() {
    int k;
    cin >> k;
    int ans = -1;
    long long mul = 7;
    for(int digit = 1; digit <= 1e7; digit++) {
        if(mul % k == 0) {
            ans = digit;
            break;
        }
        mul = (mul * 10 + 7) % k;
    }
    cout << ans;
}