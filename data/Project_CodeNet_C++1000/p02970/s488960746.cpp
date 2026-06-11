#include <bits/stdc++.h>
using namespace std;


int main() {
    
    int n, d, pos, nr;
    cin >> n >> d;
    pos = d + 1;
    nr = 1;
    while(pos + d < n) {
        nr++;
        pos += 2 * d + 1;
    }
    cout << nr;
    return 0;
}