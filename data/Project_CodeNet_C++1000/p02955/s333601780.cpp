#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned int ll;
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define rep(i, start, end) for(int i = start; i < (int)(end); ++i)
int gcd(int x, int y){
    if(x % y == 0){
        return x;
    }else{
        return gcd(x, x%y);
    }
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,0,n) cin >> a[i];
    ll sum = 0;
    rep(i,0,n) sum+=a[i];
    set<ll> s;
    for(int i = 1; i * i < sum; i++){
        if(sum % i == 0){
            s.insert(i);
            s.insert(sum/i);
        }
    }
    ll ans = 1;
    for(ll x: s){
        ll need = 1e18;
        vector<ll> r(n);
        rep(i,0,n) r[i] = a[i]%x;
        sort(r.begin(), r.end());
        ll B = 0;
        rep(i,0,n) B += x - r[i];
        ll A = 0;
        rep(i,0,n){
            A += r[i];
            B -= x - r[i];
            need = min(need, max(A,B));
        }
        if(need <= k ) ans = max(ans, x);
    }
    cout << ans << endl;
    return 0;
}