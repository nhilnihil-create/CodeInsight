#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <math.h>
#include <stack>
#include <set>
#include <deque>
#include <cmath>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
//ll mod = 998244353;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];
    vector<int> base(n);
    rep(i, n) base[i] = i + 1;
    int cnt = 1;
    int a = 0;
    int b = 0;
    do {
        bool ok = true;
        //rep(i, n) {
        //    cout << base[i] << " ";
        //}
        //cout << endl;
        rep(i, n) {
            if (base[i] != p[i]) {
                ok = false;
                break;
            }
        }
        if (ok) a = cnt;
        //cout << a << " " << cnt << endl;
        ok = true;
        rep(i, n) {
            //if (cnt == 6) cout << base[i] << " " << q[i] << endl;
            if (base[i] != q[i]) {
                ok = false;
                break;
            }
        } 
        if (ok) b = cnt;
        //if (a != 0 && b != 0) break;
        //cout << b << " " << cnt << endl;
        ++cnt;
    } while(next_permutation(base.begin(), base.end()));
    //cout << a <<  " " << b << endl;
    cout << abs(a - b) << endl;
    return 0;
}
