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
bool b[100000];

int main(){
    ll n,m; cin >> n >> m;
    ll a[n+1];a[0] = 1;
    for(int i = 0;i < m;i++){
        ll x; cin >> x;
        b[x] = true;
    }
    
    if(!b[1]) {
        a[1] = 1;
    }else{
        a[1] = 0;
    }
    
    for(int i = 2;i <= n;i++){
        a[i] = 0;
        if(!b[i]){
            if(!b[i-1]){
                a[i] += a[i-1];
            }
            if(!b[i-2]){
                a[i] += a[i-2];
            }
        }
        a[i] %= MOD;
    }
    cout << a[n];
    
    
}

