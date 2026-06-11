#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL<<60;
const int MOD = 1000000007;

ll GCD(ll x,ll y){
    if(y == 0) return x;
    else return GCD(y,x%y);
}
ll LCM(ll a,ll b){
    return a / GCD(a,b) * b;
}


int main() {
    int n; cin >> n;
    vector<double> v;
    for(int i = 0;i < n;i++){
        double x; cin >> x; v.push_back(x);
    }
    sort(v.begin(),v.end());
    double ans = (v[0]+v[1])/2;
    for(int i = 2;i < n;i++){
        ans = (ans+v[i])/2;
    }
    cout << fixed << setprecision(10) << ans;
}
