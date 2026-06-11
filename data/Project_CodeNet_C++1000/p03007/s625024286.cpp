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

    vector<ll> a(n+1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());

    int Q;  // aの0未満の要素の個数
    if(0 <= a[1]) {
        Q = 1;
    }
    else if(a[n] < 0) {
        Q = n-1;
    }
    else {
        for(int i = 2; i <= n; i++) {
            if(0 <= a[i]) {
                Q = i-1;
                break;
            }
        }
    }

    vector<pair<ll, ll>> ans(n);

    for(int i = Q+1; i <= n-1; i++) {
        ans[i-Q] = make_pair(a[1], a[i]);
        a[1] -= a[i];
    }
    for(int i = 1; i <= Q; i++) {
        ans[n-1-Q+i] = make_pair(a[n], a[i]);
        a[n] -= a[i];
    }
    
    cout << a[n] << "\n";
    for(int i = 1; i <= n-1; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
    
    return 0;
}