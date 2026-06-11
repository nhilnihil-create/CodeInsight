#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll l, r; cin >> l >> r;

    ll ans = 1e18;

    if(r - l >= 2019){
        put(0);
        return 0;
    }

    l %= 2019;
    r %= 2019;
    if(r <= l){
        ans = 0;
    }

    for(int i = l; i < r; i++){
        for(int j = i+1; j <= r; j++){
            ans = min(ans, (i * j) % 2019LL);
        }
    }
    //cout << "min1:" << min1 << " min2:" << min2 << endl;;
    put(ans);
}