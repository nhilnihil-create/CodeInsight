#include "bits/stdc++.h"

using namespace std;

void Main() {
    int n;
    cin >> n;
    int nOrg = n;

    map<int, int> fact;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            fact.insert(make_pair(i, 0));
            while (n % i == 0) {
                n /= i;
                fact[i] += 1;
            }
        }
    }
    if (n != 1) {
        fact.insert(make_pair(n, 1));
    }

    cout << nOrg << ":";
    for (auto e : fact) {
        for (int i = 0; i < e.second; ++i) {
            cout << " " << e.first;
        }
    }
    cout << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}

