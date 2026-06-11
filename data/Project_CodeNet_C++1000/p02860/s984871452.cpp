/**
    BISMILLAH
    @Author : Arham
*/
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    if(n % 2)
        cout << "No" << endl;
    else {
        int count = true;
        for(int i = 0, j = n / 2; i < n / 2; i++, j++) {
            if(s[i] != s[j]) {
                count = false;
                break;
            }
        }
        cout << (count ? "Yes" : "No") << endl;
    }

    return;
}

int main() {
    int t = true;
    //cin >> t;
    while(t--)
        solve();

    return 0;
}
