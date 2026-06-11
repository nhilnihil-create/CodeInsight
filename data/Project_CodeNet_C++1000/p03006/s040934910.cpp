#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main() {
    int n;
    cin >> n;

    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }

    map<pair<int, int>, int> mp;

    rep(i, n) {
        rep(j, n) {

            if(i == j) {
                continue;
            }

            int A = x[i] - x[j];
            int B = y[i] - y[j];

            mp[make_pair(A, B)]++;

        }
    }

    int t = 0;
    for(auto& p : mp) {
        t = max(t, p.second);
    }

    cout << n-t << endl;
    return 0;
}