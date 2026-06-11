#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;
            while (true) {
                if (((1 << k) & i) ^ ((1 << k) & j)) {
                    break;
                }
                k++;
            }
            cout << k + 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
