#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int fact(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n * fact(n - 1);
    }
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; i++) {
        cin >> r.at(i).first >> r.at(i).second;
    }
    vector<vector<double>> d(n, vector<double>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int dx = r.at(i).first - r.at(j).first;
            int dy = r.at(i).second - r.at(j).second;
            d.at(i).at(j) = sqrt(dx * dx + dy * dy);
        }
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        p.at(i) = i + 1;
    }
    double ave = 0;
    do {
        for (int i = 0; i < n - 1; i++) {
            ave += d.at(p.at(i) - 1).at(p.at(i + 1) - 1);
        }
    } while (next_permutation(p.begin(), p.end()));
    cout << setprecision(20) << ave / fact(n) << endl;
    return 0;
}