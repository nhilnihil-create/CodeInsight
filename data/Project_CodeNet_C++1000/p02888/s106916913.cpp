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
    int n; cin >> n;
    vector<int> v;
    for(int i = 0;i < n;i++){
        int x; cin >> x;v.push_back(x);
    }
    sort(v.begin(),v.end());
    int ans  = 0;
    for(int i = 0;i < n-1;i++){
        for(int j = i+1;j < n;j++){
            int c = lower_bound(v.begin(),v.end(),v[i]+v[j])-v.begin();
            ans += max(c-(j+1),0);
        }
    }
    cout << ans;
}

