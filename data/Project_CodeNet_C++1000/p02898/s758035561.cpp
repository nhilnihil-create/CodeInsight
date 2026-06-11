#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int n, k;
    cin >> n >> k;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        if (x >= k) cnt++;
    }
    cout << cnt;

    return 0;
}