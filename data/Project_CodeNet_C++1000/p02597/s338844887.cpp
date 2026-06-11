#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int r = n-1, w = 0, ans = 0;
    bool rf = false, wf = false;
    while (1) {
        while (1) {
            if (r <= w) break;
            if (s[r] == 'R') {
                rf = true;
                break;
            }
            else r--;
        } 
        while (1) {
            if (w >= r) break;
            if (s[w] == 'W') {
                wf = true;
                break;
            }
            else w++;
        }
        if (rf && wf) {
            ans++;
            r--;
            w++;
            rf = false;
            wf = false;
        }
        else break;
    }
    cout << ans << endl;
}