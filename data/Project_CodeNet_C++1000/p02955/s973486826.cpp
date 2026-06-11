#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define mfill(x,y) memset(x,y,sizeof(x))
#define all(v) v.begin(), v.end()
#define in(x,y,h,w) if(0<=x&&x<h&&0<=y&&y<w)
#define y0 y12345
#define y1 y54321

#ifdef LOCAL
#define debug(...) fprintf(stderr,__VA_ARGS__)
#else
#define debug(...) 42
#endif

using ul = unsigned long;
using ll = long long;
using P = pair<int, int>;
using vint = vector<int>;using vvint = vector<vector<int>>;
using vll = vector<ll>;using vvll = vector<vector<ll>>;
template<class T>bool chmax(T &a, const T &b){if(a<b){a=b;return 1;}return 0;}
template<class T>bool chmin(T &a, const T &b){if(a>b){a=b;return 1;}return 0;}
template <class T>void initvv(vector<vector<T> > &v, int a, int b, const T &t = T()){
    v.assign(a, vector<T>(b, t));
}
template <class T>T gcd(T &a, T &b){if(a<b){swap(a,b);} T r = a%b; while(r!=0){a=b;b=r;r=a%b;} return b;}

vint dx = {-1, 0, 1, 0}, dy = {0, -1, 0, 1};
vint dx8 = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8 = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    debug("debug test\n");
    ll n, k;cin>>n>>k;
    vll a(n);
    ll s = 0;
    rep(i, n){
        cin>>a[i];
        s += a[i];
    }
    vll y;
    for(ll i = 1;i<=sqrt(s);i++){
        if(s%i==0){y.push_back(i);y.push_back(s/i);}
    }
    sort(all(y), greater<ll>());
    vll am(n);
    vll wa(n+1, 0);
    rep(i, y.size()){
        rep(j, n){
            am[j] = a[j] - y[i]*(ll)(a[j]/y[i]);
        }
        sort(all(am));
        rep(j, n){
            wa[j+1] = wa[j]+am[j];
        }
        debug("test %d\n", y[i]);
        rep(j, n+1){
            if( ( wa[j]-(y[i]*(n-j)-(wa[n]-wa[j])) )%y[i]==0 && wa[j]<=k&& (y[i]*(n-j)-(wa[n]-wa[j]))<=k){
                cout << y[i] << endl;
                return 0;
            }
        }
    }


    return 0;
}
