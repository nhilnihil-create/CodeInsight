// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

ll f(vector<ll> &a, double x){
    int n = a.size();
    ll ret = 0LL;
    rep(i,n) ret += ll((a[i]*1.0)/x);
    return ret;
}

ll roundup(double x){
    if(ll(x) == x) return ll(x);
    return ll(x+1.0);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; ll k; cin >> n >> k;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    long double left = 0, right = a[0], mid;
    
    while(abs(left - right) >= 1e-3){
        mid = (left + right)/2.0;
        if(f(a, mid) <= k) right = mid; // ok
        else left = mid; // false
    }

    cout << roundup(mid) << endl;
}