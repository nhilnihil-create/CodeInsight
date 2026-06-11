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

int main() {
    int n;
    cin >> n;
    int d[n];

    int sum = 0;
    rep(i, n) {
        cin >> d[i];
        sum += d[i];
    }

    int ans = 0;
    rep(i, n) { ans += (sum - d[i]) * d[i]; }

    cout << ans / 2 << endl;
}