#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

int main(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N) cin >> a[i];
    ll ans = 1;
    ll limit = pow(10, 18);
    //0の確認
    rep(i, N){
        if(a[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    rep(i, N){
        if(ans <= (limit / a[i])){
            ans *= a[i];
        }else{
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}