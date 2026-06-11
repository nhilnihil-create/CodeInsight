#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll GetDigit(ll num){ return log10(num)+1; } //numの桁数を求める

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> c(n-1);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n-1) cin >> c[i];

    int ans = 0;
    rep(i,n){
        a[i]--;
    }
    rep(i,n){
        ans += b[a[i]];
        if(i != 0){
            if(a[i] == a[i-1] + 1) ans += c[a[i-1]];
        }
    }
    cout << ans << endl;
    return 0;
}