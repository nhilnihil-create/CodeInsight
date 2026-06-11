/**
 *   @FileName	a.cpp
 *   @Author	kanpurin
 *   @Created	2020.08.12 18:44:24
**/

#include "bits/stdc++.h" 
using namespace std; 
typedef long long ll;

int main() {
    int n;cin >> n;
    string s;cin >> s;
    vector<int> t(n-1);
    bool two = true;
    for (int i = 0; i < n-1; i++) {
        t[i] = abs(s[i] - s[i+1]);
        if (t[i] == 1) two = false;
    }
    if (two) {
        for (int i = 0; i < n-1; i++) {
            t[i] /= 2;
        }
    }
    else {
        for (int i = 0; i < n-1; i++) {
            t[i] %= 2;
        }
    }
    int ans = 0;
    for (int i = 0; i <= n-2; i++) {
        if (t[i] == 1 && ((n-2)&i)==i) {
            ans ^= 1;
        }
    }
    if (two) {
        cout << ans * 2 << endl;
    }
    else {
        cout << ans << endl;
    }
    return 0;
}
