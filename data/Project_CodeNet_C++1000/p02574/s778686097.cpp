#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long a[n + 1];
    for(long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long gcd = a[1];
    for(long long i = 2; i <= n; i++) {
        gcd = __gcd(gcd, a[i]);
    }
    if(gcd != 1) {
        cout << "not coprime\n";
        return 0;
    }
    set<long long> Prime, ThisOne;
    for(long long i = 1; i <= n; i++) {
        ThisOne.clear();
        for(long long j = 2; j <= sqrt(a[i]); j++) {
            if(a[i] % j == 0) {
                if(Prime.count(j) && !ThisOne.count(j)) {
                    cout << "setwise coprime\n";
                    return 0;
                }
                Prime.insert(j);
                ThisOne.insert(j);
                a[i] /= j;
                j--;
            }
        }
        if(a[i] != 1) {
            if(Prime.count(a[i]) && !ThisOne.count(a[i])) {
                cout << "setwise coprime\n";
                return 0;
            }
            Prime.insert(a[i]);
            ThisOne.insert(a[i]);
        }
    }
    cout << "pairwise coprime\n";
}
