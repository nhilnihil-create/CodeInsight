#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n, minv, maxv=-1000000000;
    cin >> n;
    cin >> minv;
    for (int i=1; i<n; i++) {
        int k;
        cin >> k;
        maxv = max(maxv, k-minv);
        minv = min(minv, k);
    }
    cout << maxv << endl;
}


