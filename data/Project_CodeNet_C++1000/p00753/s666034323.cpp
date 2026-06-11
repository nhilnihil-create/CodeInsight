#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> p(123456 * 2 + 1, 1);
    p[0] = p[1] = 0;
    for (int i = 2; i < p.size(); i++) {
        if (p[i] == 0) continue;
        for (int j = 2; i * j < p.size(); j++) {
            p[i * j] = 0;
        }
    }

    for (int i = 1; i < p.size(); i++) {
        p[i] += p[i-1];
    }

    
    int n;
    while (cin >> n, n) {
        cout << p[n * 2] - p[n] << endl;
    }

    return 0;
}

