#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 1, t = i ^ j;; k++, t >>= 1) {
                if (t & 1) {
                    cout << k << " \n"[j == n - 1];
                    break;
                }
            }
        }
    }

    return 0;
}