#include <bits/stdc++.h>
using namespace std;

int main() {
    int64_t n, dvs = 1;
    cin >> n;
    for (int64_t i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            dvs = i;
        }
    }
    cout << dvs + (n / dvs) - 2 << endl;
}
