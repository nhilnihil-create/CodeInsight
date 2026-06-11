#include <bits/stdc++.h>
using namespace std;

int n, k, x, nr;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        if(x >= k) {
            nr++;
        }
    }
    cout << nr;
    return 0;
}