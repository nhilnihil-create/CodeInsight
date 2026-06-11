#include <bits/stdc++.h>
using namespace std;

const int MAXN = 300000;
int cum[MAXN];

void sieve() {
    for (int i = 0; i < MAXN; i++) cum[i] = 1;
    for (int i = 2; i < MAXN; i++) {
        if (cum[i]) {
            for (int j = 2 * i; j < MAXN; j += i) {
                cum[j] = 0;
            }
        }
    }
}

int main() {
    sieve();
    for (int i = 1; i < MAXN; i++) {
        cum[i] += cum[i - 1];
    }
    int n;
    while (cin >> n, n) {
        cout << cum[2 * n] - cum[n] << endl;
    }
}
