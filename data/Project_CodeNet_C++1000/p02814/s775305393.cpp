#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
const int INF = 1001001001;


ll gcd(ll a,ll b){
    if(a < b){
        ll t = a;
        a = b;
        b = t;
    }
    ll r = a % b;
    while(r != 0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}


// ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){
    return a / gcd(a,b) * b;
}
// ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int f(int x){
    int res = 0;
    while(x % 2 == 0){
        x /= 2;
        res++;
    }
    return res;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a.at(i);
    rep(i,n) a.at(i) /= 2;
    
    int t = f(a.at(0));
    rep(i,n){
        int l = f(a.at(i)); 
        if(l != t){
            cout << 0 << endl;
            return 0;
        }
        a.at(i) >>= t;
    }
    m >>= t;
    ll l = 1;
    rep(i,n){
        l = lcm(l,a.at(i));
        if(l > m){
            cout << 0 << endl;
            return 0;
        }
    }
    m /= l;
    ll ans = (m + 1) / 2;
    cout << ans << endl;
    return 0;
}