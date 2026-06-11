#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

bool is_int(vector<int> a, vector<int> b, int d) {
    vector<int> temp(d);
    int total = 0;
    rep(i, d) {
        temp[i] = a[i] - b[i];
        temp[i] *= temp[i];
        total += temp[i];
    }

    bool ans = false;

    rep(i, total + 1) {
        if(i * i == total) {
            ans = true;
        }
    }

    return ans;
}

int main() {
    int n, d;
    cin >> n >> d;

    vector<vector<int>> x(n, vector<int>(d));
    rep(i, n) {
        for(int j = 0; j < d; ++j) {
            cin >> x[i][j];
        }
    }

    int ans = 0;
    rep(i, n) {
        for(int j = i + 1; j < n; ++j) {
            if(is_int(x[i], x[j], d)) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}