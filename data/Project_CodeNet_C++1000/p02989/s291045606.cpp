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
    vector<int> d;

    int temp = 0;
    rep(i, n) {
        cin >> temp;
        d.push_back(temp);
    }
    sort(d.begin(), d.end());
    /*
        rep(i, n) { cout << d[i] << ","; }
        cout << endl;
    */
    int center = (n / 2) - 1;
    int ans = d[center + 1] - d[center];
    // cout << center << endl;
    cout << ans << endl;
}