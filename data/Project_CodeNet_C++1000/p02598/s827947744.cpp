// AtCoder template
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i = 0; i < n; ++i)

ll f(vector<ll> &a, ll x){
    int n = a.size();
    ll ret = 0LL;
    rep(i,n) ret += (a[i] + x - 1)/x - 1;
    return ret;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n; ll k; cin >> n >> k;
    vector<ll> a(n); rep(i,n) cin >> a[i];
    sort(a.begin(), a.end(), greater<ll>());

    ll left = 0, right = a[0], mid;
    
    while(abs(left - right) > 1){
        mid = (left + right) / 2;
        if(f(a, mid) <= k) right = mid; // ok
        else left = mid; // false
    }

    cout << right << endl;
}