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
    vector<int> a(n);
    vector<int> b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int l, r;
    if (n%2 == 1) {
        l = a[n/2];
        r = b[n/2];
    }
    else {
        l = a[n/2] + a[n/2-1];
        r = b[n/2] + b[n/2-1];
    }
    cout << r - l + 1 << endl; 
    return 0;
}
