#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}

ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}

const int MOD = 1000000007;


//void warshall_floyd(int n){
//    for(int k=0;k<n;k++){
//        for(int i=0;i<n;i++){
//            for(int j=0;j<n;j++){
//                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
//            }
//        }
//    }
//}
//ll calc_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        ++res;
//        N /= 10;
//    }
//    return res;
//}
//ll sum_digit(ll N) {
//    ll res = 0;
//    while (N) {
//        res += N % 10;
//        N /= 10;
//    }
//    return res;
//}


int main(){
    ll n; cin >> n;
    vector<ll> v;
    for(int i = 0;i < n;i++){
        ll x; cin >> x;
        v.push_back(x);
    }
    ll ans = 1000;ll k = 0;
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 1;i < v.size();i++){
        if(v[i] > v[i-1]){
            k = 0;
            k = ans/v[i-1];
            ans -= k*v[i-1];
            ans += k*v[i];
        }
    }
    cout << ans;
}

