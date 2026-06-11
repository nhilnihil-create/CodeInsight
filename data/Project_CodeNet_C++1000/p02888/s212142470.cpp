#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main() {
    int n; cin >> n;
    int ans = 0;
    vector<int> L(n);
    rep(i,n) cin >> L[i];
    sort(L.begin(),L.end());
    for(int a = 0; a < n; a ++)
    {   for(int b = a+1; b < n; b ++) {
            int ab = L[a] + L[b];
            int r = lower_bound(L.begin(), L.end(), ab) - L.begin();
            int l = b + 1;
            ans += max(0, r - l);
        }
    }

    cout << ans;


    return 0;
}
