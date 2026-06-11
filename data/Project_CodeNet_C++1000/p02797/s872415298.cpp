#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, s;
    cin >> n >> k >> s;
    for (int i=0; i<n; ++i) {
        if (i < k) cout << s;
        else {
            if (i%2) cout << s/2+100;
            else cout << s/2+10;
        }
        if (i == n-1) cout << endl;
        else cout << " ";
    }
}