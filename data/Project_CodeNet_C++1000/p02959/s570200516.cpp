#include<bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)n; i++)
#define repa(i, s, n) for(int i = s; i < (int)n; i++)
using namespace std;
using ll = long long;
typedef vector<int> vi;


signed main() {
    int cnt = 0;
    int n;
    cin >> n;
    vi a(n+1), b(n);
    rep(i, n+1) cin >> a[i];
    rep(i, n) cin >> b[i];

    rep(i, n){
        if(a[i] <= b[i]){
            cnt += a[i];
            /* cout << a[i] << " "; */
            b[i] -= a[i];
            if(a[i+1] >= b[i]){
                a[i+1] -= b[i];
                cnt += b[i];
            }else{
                cnt += a[i+1];
                a[i+1] = 0;
            }
        }else{
            cnt += b[i];
            /* cout << b[i] << " "; */
            b[i] = 0;
        }
    }
    /* cout << "\n"; */

    cout << cnt << endl;
}