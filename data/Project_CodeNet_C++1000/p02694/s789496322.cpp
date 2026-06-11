#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e5 + 7;

#include <math.h>
#define PI 3.14159265358979323846264338327950L

int main() {
    long long x;
    cin >> x;
    long long cant = 100;
    int ans = 0;
    while (cant < x) {
        cant += cant / 100;
        ans++;
    }
    cout << ans;
    return 0;
}