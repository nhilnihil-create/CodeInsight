#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
using ll = long long int;

int main()
{
    int n, m, k, t; cin >> n >> m >> k;
    vector<ll> sa(n+1), sb(m+1);
    sa[0] = sb[0] = 0;
    rep(i, n){
        cin >> t;
        sa[i+1] = sa[i] + t; 
    }
    rep(i, m){
        cin >> t;
        sb[i+1] = sb[i] + t;
    }

    int al = 0, ar = n+1;
    while(ar - al > 1){
        int am = (al + ar)/2;
        if(sa[am] <= k) al = am;
        else ar = am;
    }

    int ans = 0, cnt;
    for(int a = al; a >= 0; a--){
        cnt = a;
        int b_time = k - sa[a];

        int bl = 0, br = m+1;
        while(br - bl > 1){
            int bm = (bl + br)/2;
            if(sb[bm] <= b_time) bl = bm;
            else br = bm;
        }

        cnt += bl;
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}