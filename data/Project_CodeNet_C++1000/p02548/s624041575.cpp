#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i, j;
    int cnt = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n/i; j++) {
            if (i*j < n) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
}
