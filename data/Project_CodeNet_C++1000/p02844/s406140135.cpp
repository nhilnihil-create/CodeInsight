#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (int k = 0; k < 10; k++) {
                bool f1 = false;
                bool f2 = false;
                bool f3 = false;
                for (auto iter = begin(s); iter != end(s); iter++) {
                    // cout << *iter -  << endl;
                    if (!f1) {
                        if (*iter - '0' == i) {
                            f1 = true;
                        }
                        continue;
                    }
                    if (!f2) {
                        if (*iter - '0' == j) {
                            f2 = true;
                        }
                        continue;
                    }
                    if (!f3) {
                        if (*iter - '0' == k) {
                            f3 = true;
                        }
                    }
                }
                // cout << f1 << f2 << f3 << endl;
                if (f1 && f2 && f3) {
                    ans++;
                }
            }
        }
    }   
    cout << ans << endl; 
    return 0;
}