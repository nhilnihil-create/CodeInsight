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

    vector<int> W(n);
    int rightSum = 0;
    rep(i, n) {
        int weight;
        cin >> weight;
        W.at(i) = weight;
        rightSum += weight;
    }

    int leftSum = 0;
    int diff = 101 * 101;
    for (size_t i = 0; i < W.size(); i++) {
        leftSum += W.at(i);
        rightSum -= W.at(i);
        diff = min(diff, abs(rightSum - leftSum));
    }

    cout << diff << endl;
}
