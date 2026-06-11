#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    int n,a[25],b,c[25];
    cin >> n;
    int ans = 0;
    rep(i,n) cin >> a[i];
    rep(i,n){
        cin >> b;
        ans += b;
    }
    rep(i,n-1) cin >> c[i];

    for(int i = 1; i < n; ++i){
        if(a[i] == a[i-1] + 1){
            ans += c[a[i-1]-1];
        }
    }
    cout << ans << endl;
    return 0;
}