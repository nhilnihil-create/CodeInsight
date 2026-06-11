#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int main() {
    fastIO;
    int n;
    cin >> n;
    vector<double> A(n);
    rep(i, n) cin >> A.at(i);

    double rev = 0;
    for (auto a : A) {
        rev += 1 / a;
    }
    cout << precise(20) << (1 / rev) << endl;
}