#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll,ll> l_l;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
const int INF=1001001000;
const int mINF=-1001001000;
const ll LINF=1010010010010010000;
template<class T> inline bool chmin(T& a, T b) {
if (a > b) {
a = b;
return true;
}
return false;
}
template<class T> inline bool chmax(T& a, T b) {
if (a < b) {
a = b;
return true;
}
return false;
}
int main(){
    ll n,m,v,p;cin >> n >> m >> v >> p;
    vi a(n);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end());
    int l=-1,r=n-1;
    while(r>l+1){
        int mid=(r+l)/2;
        vl b;
        ll base=a[mid]+m;
        rep(i,n){
            if(i!=mid) b.push_back(a[i]);
        }
        reverse(b.begin(),b.end());
        ll ok=0;
        int ng=0;
        rep(i,n-1){
            if(i<p-1) ok+=m;
            else if(base>=b[i]) ok+=min(m,base-b[i]);
            else ng=1;
        }
        if(ng){
            l=mid;
        }
        else if(ok>=m*(v-1)) r=mid;
        else l=mid;
        //cout << l << " " << r << endl;
    }
    cout << n-r << endl;
    return 0;
}