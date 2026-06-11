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
    vector<int> v;
    for(int i = 0;i < n;i++){
        int x; cin >> x; v.push_back(x);
    }
    sort(v.begin(),v.end());
    cout << v[n/2] - v[n/2-1];
}
