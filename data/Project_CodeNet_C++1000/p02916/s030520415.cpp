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

    vector<int> A(n);
    rep(i, n) cin >> A.at(i);

    vector<int> B(n);
    rep(i, n) cin >> B.at(i);

    vector<int> C(n - 1);
    rep(i, n - 1) cin >> C.at(i);

    int sum = 0, prev = -1;
    for (auto a : A) {
        sum += B.at(a - 1);
        if (prev + 1 == a) {
            sum += C.at(prev - 1);
        }
        prev = a;
    }
    cout << sum << endl;
}