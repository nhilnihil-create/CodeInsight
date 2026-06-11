#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main() {
    int n;
    cin >> n;
    double sum = 0;
    rep(i, n) {
        double a;
        cin >> a;
        sum += 1 / a;
    }
    printf("%12f", 1 / sum);
}