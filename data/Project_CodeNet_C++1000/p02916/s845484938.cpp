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
    int n; cin >> n;
    vector<int> a,b,c;
    for(int i = 0;i < n;i++){
        int x; cin >> x; a.push_back(x);
    }
    for(int i = 0;i < n;i++){
        int x; cin >> x; b.push_back(x);
    }
    for(int i = 0;i < n-1;i++){
        int x; cin >> x; c.push_back(x);
    }
    
    int ans = 0;
    for(int i = 0;i < a.size();i++){
        ans += b[a[i]-1];
        if(i >= 1 && a[i] == a[i-1]+1) ans+=c[a[i-1]-1];
    }
    
    cout << ans;
}
