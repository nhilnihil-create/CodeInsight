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
    double a[n];
    double total = 0;
    rep(i, n) {
        cin >> a[i];
        total += 1 / a[i];
    }

    cout << fixed << setprecision(15) << 1 / total << endl;
}