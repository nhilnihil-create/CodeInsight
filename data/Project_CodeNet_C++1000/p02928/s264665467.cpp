#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<long long> V;
typedef vector<V> VV;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<62;
const int INF = 1<<30;
const double PI=acos(-1);
ll mod=1000000000+7;
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}
ll lensum(ll n){
    ll res=n*(n+1);
    return(((res%mod)*modinv(2,mod))%mod);
}
int main(){
    int n,k;
    ll ans=0LL;
   
    cin >>n>>k;
    vector<int>a(n,0);
    vector<pair<int,int>>touth(n,pair<int,int>(0,0));
    rep(i,n){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i] >a[j]){
                touth[i].F++;
            }else if(a[i] <a[j]){
                touth[j].S++;
            }
        }
    }
    //rep(i,n){
  //      clog <<touth[i].F <<" "<<touth[i].S<<endl;
//    }
    for(int i=0;i<n;i++){
        ans+=(touth[i].F*lensum(k));
        ans%=mod;
        ans += (touth[i].S * lensum(k-1));
        ans %= mod;
    }
    cout<<ans<<endl;
}