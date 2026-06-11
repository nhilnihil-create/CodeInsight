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
    ll n;cin >> n;
    vector<ll> v;
    for(int i = 0;i < n;i++){
        ll x; cin >> x;
        if(x==0){
            cout << 0 << endl;
            return 0;
        }else{
            v.push_back(x);
        }
    }
    ll num = 1;
    for(int i = 0;i < n;i++){
        if(v[i] <=1000000000000000000/num){
            num *=v[i];
        }else{
            cout << -1;
            return 0;
        }
    }
    cout << num;
}

