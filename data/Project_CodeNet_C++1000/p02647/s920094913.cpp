#include<bits/stdc++.h>

using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)

using ll = long long;
using P = pair<int, int>;

const int mod = 998244353;

int main(int, char**)
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    rep(i,n) cin >> a[i];

    rep(_,k) {
        vector<int> d(n, 0);
        int endcntl = 0, endcntr = 0;
        rep(i,n) {
            int l = max(0, i-a[i]);
            int r = min(n-1, i+a[i]);
            d[l]++;
            if (r+1 < n) d[r+1]--;
            if (l==0) endcntl++;
            if (r+1 >= n) endcntr++;
        }
        rep(i,n) {
            if (!i) a[i] = d[i];
            else a[i] = a[i-1] + d[i];
        }
        if (endcntl == n && endcntr == n) break;
    }
    rep(i,n) {
        if (i) cout << " ";
        cout << a[i];
    }
    cout << endl;

    return 0;
}