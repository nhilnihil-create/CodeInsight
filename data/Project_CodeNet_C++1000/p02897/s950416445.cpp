#include <bits/stdc++.h>
using namespace std;

double n, nr;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(i % 2) {
            nr++;
        }
    }
    cout << (nr / n);
    return 0;
}