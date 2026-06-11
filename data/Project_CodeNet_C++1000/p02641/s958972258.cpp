#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define invrep(i,n) for(int i = (int)(n)-1; i >= 0; i--)
using ll = long long;

int main() {
    int x, n;
    cin >> x >> n;
    int tmp;
    if (n == 0) {
        // cin >> tmp;
        cout << x << endl;
        return 0;
    }

    vector<int> p(n);
    rep(i, n) cin >> p[i];
    sort(p.begin(), p.end());

    int min_tmp = 101;
    int near;
    invrep(i, n) {
        tmp = abs(x - p[i]);
        if (tmp < min_tmp) {
            min_tmp = tmp;
            near = p[i];
        }
    }

    int near_neg = near - 1;
    int near_pos = near + 1;
    invrep(i, n) {
        if (near_neg == p[i]) {
            near_neg = p[i] - 1;
        }
    }
    rep(i, n){
        if (near_pos == p[i]) {
            near_pos = p[i] + 1;
        }
    }

    if (abs(x - near_neg) <= abs(x - near_pos)) cout << near_neg << endl;
    else cout << near_pos << endl;
    return 0;
}