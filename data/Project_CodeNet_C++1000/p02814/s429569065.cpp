#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int f(int x) {
    int res = 0;
    while(x%2==0) {
        res++;
        x /= 2;
    }
    return res;
}

int main() {
    int n;ll m;
    cin >> n >> m;
    vector<int>a(n);
    rep(i,n) cin >> a[i];
    rep(i,n) a[i] /= 2;
    int t = f(a[0]);
    rep(i,n) {
        if(t != f(a[i])) {
            cout << 0 << endl;
            return 0;
        }
        a[i] >>= t;
    }
    m >>= t;
    ll l = 1;
    rep(i,n) {
        l = lcm(l,a[i]);
        if(l>m) {
            cout << 0 << endl;
            return 0;
        }
    }
    m /= l;
    int ans = (m+1)/2;
    cout << ans << endl;
}