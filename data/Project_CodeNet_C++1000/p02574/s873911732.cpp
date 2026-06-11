/*input
3
6 10 16
*/

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int A = 1000005;

// antbook p108
int gcd(int a, int b) {
    if (b == 0) return abs(a);
    return gcd(b, a%b);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> c(A);
    rep(i, n) {
        cin >> a[i];
        c[a[i]]++;
    }

    bool pairwise = true;
    for (int i = 2; i < A; i++) {
        int cnt = 0;
        for (int j = i; j < A; j += i) {
            cnt += c[j];
        }
        if (cnt > 1) {
            pairwise = false;
            break;
        }
    }
    if (pairwise) {
        puts("pairwise coprime");
        return 0;
    }

    int g = 0;
    rep(i, n) g = gcd(g, a[i]);
    if (g == 1) {
        puts("setwise coprime");
        return 0;
    }
    puts("not coprime");
}