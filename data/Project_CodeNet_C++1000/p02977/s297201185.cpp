#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
 
    if ((n & -n) == n) {
        cout << "No";
        return 0;
    }
 
    int logn = 0;
    while ((1 << (logn + 1)) - 1 <= n) logn++;

    cout << "Yes\n";
 
    for(int i = 1; i < (1 << logn) - 1; i++) {
        cout << i << " " << i + 1 << '\n'; 
        cout << n + i << " " << n + i + 1 << '\n';
    }
    cout << (1 << logn) - 1 << " " << n + 1 << '\n';
    
    int tar = -1;
    if ((n - (1 << logn) + 1) % 2) {

        int lastBit = n & - n;
        //cout << lastBit << '\n';
        tar = n ^ lastBit;
        cout << tar << " " << tar + 1 << '\n';
        cout << tar << " " << lastBit << '\n';
        cout << lastBit + 1 << " " << n + tar + 1 << '\n';
        cout << n + tar <<  " " << n + tar + 1 << '\n';
        cout << n << " " << tar << '\n';
        cout << 2 * n << " " << lastBit << '\n';
    }
    for(int i = (1 << logn); i < n; i += 2) if (i != tar) {
        cout << i << " " << i + 1 << '\n';
        cout << i + 1 << " " << 1 << '\n';
        cout << i + n << " " << 1 << '\n';
        cout << i + 1 + n << " " << i + n << '\n';
    }
}
