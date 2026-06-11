#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0;i < n;++i)
#define all(v) v.begin(),v.end()
using namespace std;
using ll = long long;
typedef pair<int,int> P;

const int INF = 1001001001;

ll gcd(ll a,ll b) {
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return a/gcd(a,b)*b;
}

int f(int x){
    int res = 0;
    while(x%2 == 0){
        x /= 2;
        res++;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i,n) cin >> a[i];

    rep(i,n){
        a[i] = a[i]/2;
    }

    int t = f(a[0]);
    rep(i,n){
        if(t != f(a[i])){
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t;
    }
    m >>= t;
    
    ll l = 1;
    rep(i,n){
        l = lcm(l,a[i]);
        if(l > m){
            cout << 0 << endl;
            return 0;
        }
    }
    m /= l;
    int ans = (m+1)/2;
    cout << ans << endl;

    cout << endl;
    return 0;
}
