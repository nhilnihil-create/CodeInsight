#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long x;
    cin >> x;
    long long yen = 100;
    int years = 0;
    while (yen < x) {
        yen += yen/100;
        years++;
    }
    cout << years;
}
