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
#include <cassert>
#include <cstring>

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    ll kabu = 0;
    ll money = 1000;
    bool upflg = false;
    bool dnflg = true;
    rep(i, n) {
        if (i == n - 1) {
            if (kabu != 0) {
                money += kabu * (ll)a[i];
            }
        }
        else {
            if (dnflg && (ll)a[i] < (ll)a[i+1]) {
                kabu = money / (ll)a[i];
                money = money % (ll)a[i];
                dnflg = false;
                upflg = true;
            }
            if (upflg && (ll)a[i] > (ll)a[i+1]) {
                money += kabu * (ll)a[i];
                kabu = 0LL;
                dnflg = true;
                upflg = false;
            }
        }
        //cout << i << " " << money << " " << kabu << endl;
    }
    cout << money << endl;
    return 0;
}
