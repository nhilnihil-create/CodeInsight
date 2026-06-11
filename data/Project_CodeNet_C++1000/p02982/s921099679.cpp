#include <bits/stdc++.h>
#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define precise(i) fixed << setprecision(i)
using llint = long long int;
using namespace std;

int dist(const vector<int> x, const vector<int> y) {
    int sum = 0;
    for (size_t i = 0; i < x.size(); i++) {
        sum += (x.at(i) - y.at(i)) * (x.at(i) - y.at(i));
    }
    return sum;
}

int main() {
    fastIO;
    int n, d;
    cin >> n >> d;
    vector<vector<int>> Pi(n, vector<int>(d));
    rep(i, n) {
        rep(j, d) { cin >> Pi.at(i).at(j); }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; j++) {
            int x = dist(Pi.at(i), Pi.at(j));
            int isZ = sqrt((double)x) * 10000;
            if (isZ % 10000 == 0)
                cnt++;
        }
    }
    cout << cnt << endl;
}