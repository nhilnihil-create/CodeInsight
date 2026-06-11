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

double average(double a, double b) { return (a + b) / 2.0; }

int main() {
    int n;
    cin >> n;
    vector<double> v;
    double temp;
    rep(i, n) {
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    double ans = v[0];
    rep(i, n) { ans = average(ans, v[i]); }

    cout << fixed << setprecision(15) << ans << endl;
}