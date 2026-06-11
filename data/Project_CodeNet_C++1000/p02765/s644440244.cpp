#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n, r;
    cin >> n >> r;
    int inner = r;
    if (n < 10) {
        inner = 100 * (10 - n) + r;
    }
    
    cout << inner << endl;
    return 0;
}
