#include <bits/stdc++.h>

using namespace std;


int main() {
    int x;
    cin >> x;
    int ans;
    if(x < 2000) {
        ans = 1;
    }
    if(x < 1800) {
        ans = 2;
    }
    if(x < 1600) {
        ans = 3;
    }
    if(x < 1400) {
        ans = 4;
    }
    if(x < 1200) {
        ans = 5;
    }
    if(x < 1000) {
        ans = 6;
    }
    if(x < 800) {
        ans = 7;
    }
    if(x < 600) {
        ans = 8;
    }
    cout << ans << "\n";
    return 0;
}