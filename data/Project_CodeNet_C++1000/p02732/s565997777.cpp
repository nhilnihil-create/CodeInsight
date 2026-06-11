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

int main() {
    int n;cin >> n;
    vector<ll>v;multimap<ll,ll>m;
    for(int i = 0;i < n;i++){
        ll x; cin >> x;
        v.push_back(x);
        auto z = m.find(x);
        if(z == m.end()){
            m.insert(make_pair(x,1));
        }else{
            z->second++;
        }
    }
    ll sum  = 0;
    
    for(auto f: m){
        ll g = (f.second*(f.second-1))/2;
        sum += g;
    }
    
    for(int i = 0;i < n;i++){
        ll plus = (m.find(v[i])->second-1)*(m.find(v[i])->second-2);
        plus/=2;
        ll minus = (m.find(v[i])->second)*(m.find(v[i])->second-1);
        minus/=2;
        cout << sum - minus + plus << endl;
    }
    
}


