#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, d;
    int ret = 0;
    cin >> n >> d;

    for(int i = 0; i < n; i++) {
        long long p, q;
        cin >> p >> q;

        if(sqrt(p * p + q * q) <= (long long)d) {
            ret++;
        }
    }

    cout << ret << endl;
}