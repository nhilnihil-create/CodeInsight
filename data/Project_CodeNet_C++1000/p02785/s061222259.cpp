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


int main() {
    int n,k; cin >> n >> k;
    vector<int> v;
    for(int i = 0;i < n;i++){
        int x; cin >> x; v.push_back(x);
    }
    sort(v.begin(),v.end(),greater<int>());
    if(v.size() <= k){
        cout << 0;
    }else{
        ll ans = 0;
        for(int i = k;i < n;i++){
            ans += v[i];
        }
        cout << ans;
    }
    
}


