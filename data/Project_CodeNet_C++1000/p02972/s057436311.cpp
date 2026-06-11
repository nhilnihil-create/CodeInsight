#include <bits/stdc++.h>
using namespace std;

const int NMAX = 2e5 + 5;
int n, a[NMAX], b[NMAX], nr;

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    b[n] = a[n] % 2;
    nr = b[n];
    for(int i = n - 1; i >= 1; i--) {
        int sum = 0;
        for(int j = i; j <= n; j += i) {
            sum += b[j];
        }
        if(sum % 2 != a[i] % 2) {
            b[i] = 1;
        }
        nr += b[i];
    }
    cout << nr << '\n';
    for(int i = 1; i <= n; i++) {
        if(b[i] == 1) {
            cout << i << ' ';
        }
    }
    return 0;
}