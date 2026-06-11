#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
using ll = long long;

int main() {
    int n, k, d, s;
    cin >> n >> k;
    int ans = 0;
    vector<bool> a(n, false);

    for (int i = 0; i < k; i++) {
        cin >> d;
        for (int j = 0; j < d; j++) {
            cin >> s;
            a.at(s - 1) = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (a.at(i) == false) {
            ans++;
        }
    }
    cout << ans << endl;
    
}