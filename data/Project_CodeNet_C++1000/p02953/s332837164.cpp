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

using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main() {
    int n;
    cin >> n;
    vector<ll> h(n);
    rep(i, n) cin >> h[i];
    rep(i, n-1) {
        if (h[i] - h[i+1] >= 2) {
            cout << "No" << endl;
            return 0; 
        }
        if (h[i] - h[i+1] == 1) {
            ++h[i+1];
        }
    }
    cout << "Yes" << endl;
    return 0;
}
