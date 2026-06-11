#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define rrep(i,a,b) for(int i=a;i>=b;i--)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=(1<<30)-1;
const int mod=1e9+7;
int dx[8]={1,0,-1,0,-1,-1,1,1};
int dy[8]={0,1,0,-1,-1,1,-1,1};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n,k;cin >> n >> k;
    vector<ll> a(n),f(n);
    rep(i,0,n){
        cin >> a[i];
    }
    rep(i,0,n){
        cin >> f[i];
    }
    sort(a.begin(),a.end());
    sort(f.begin(),f.end(),greater<ll>());
    ll l=-1,r=INF;
    while(r-l>1){
        ll mid=(l+r)/2;
        ll sum=0;
        rep(i,0,n){
            sum+=max(0LL,a[i]-mid/f[i]);
        }
        if(sum>k){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    cout << r << endl;
}