#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;

int main(){
    int n;  cin >> n;
    ll a[n+1],b[n];
    rep(i,n+1)    cin >> a[i];
    rep(i,n)    cin >> b[i];

    ll ans(0);
    rep(i,n){
        if(a[i]<=b[i]){
            ans += a[i];
            b[i] -= a[i];
            a[i] = 0;
        }else{
            ans += b[i];
            a[i] -= b[i];
            b[i] = 0;
        }

        if (a[i+1]<=b[i]){
            ans += a[i + 1];
            b[i] -= a[i];
            a[i+1] = 0;
        }else{
            ans += b[i];
            a[i + 1] -= b[i];
            b[i] = 0;
        }
    }

    cout << ans << endl;

    return 0;
}