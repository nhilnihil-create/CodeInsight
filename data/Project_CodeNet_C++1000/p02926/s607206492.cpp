#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl; 
#define INF 1000000000
#define mod 1000000007
typedef long long ll;
const ll LINF = 1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout<<fixed<<setprecision(12);


    int n;cin>>n;
    vector<complex<long double>> v(n);
    rep(i,n){
        long double x,y;
        cin>>x>>y;
        v[i]=complex<long double>(x,y);
    }
    sort(ALL(v),[&](complex<long double> a,complex<long double> b){
        return arg(a)<arg(b);
    });
    long double ans=0;
    rep(i,n){
        complex<long double> sum=(0,0);
        rep(j,n){
            sum+=v[(i+j)%n];
            chmax(ans,abs(sum));
        }
    }
    cout<<ans<<endl;
    return 0;
}
