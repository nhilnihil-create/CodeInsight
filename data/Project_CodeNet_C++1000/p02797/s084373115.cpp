#include <bits/stdc++.h>
#define rep(i, n) for(ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const double PI=acos(-1);

int main(){
    ll n, k, s;
    cin >> n >> k >> s;
    ll a[2] = {s/2, s%2 == 1 ? s/2 + 1 : s/2};
    rep(i, n){
        if(i > 0) cout << " ";
        if(k == n){
            cout << s;
            continue;
        }
        if(i <= k){
            if(s != 1) cout << a[i%2];
            else if(s == 1 && i < k) cout << "1";
            else cout << "2";
        }else{
            if(s == 1000000000) cout << "1";
            else cout << s+1;
        }
    }
    cout << endl;
    return 0;
}