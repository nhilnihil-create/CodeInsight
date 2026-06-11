#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> num(1000010);
    int g = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(a[i], g);
        num[a[i]]++;
    }

    int i;
    for (i = 2; i <= 1000010; i++) {
        int x = 0;
        for (int j = i; j <= 1000010; j += i) x += num[j];
        if (x > 1) break;
    }

    if (i == 1000011) {
        cout << "pairwise coprime" << endl;
        return 0;
    }

    if (g == 1) {
        cout << "setwise coprime" << endl;
    }
    else {
        cout << "not coprime" << endl;
    }
}