#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pinin=pair<int ,int>;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sort(x) sort(x.begin(), x.end());
#define rese(x) reverse(x.begin(), x.end());
#define vnn(x,y,name) vector<vector<int>> name(x, vector<int>(y));

string yes="Yes",no="No";

int main() {
    ll n,m,k;
    cin>>n>>m>>k;
    vll a(n),b(m);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];
    vll bsum(m+1,0),asum(n+1,0);
    rep(i,m) bsum[i+1]=bsum[i]+b[i];
    rep(i,n) asum[i+1]=asum[i]+a[i];
    ll ans=0;
    rep(i,n+1){
        if(asum[i]>k) break;
        ll ok=-1,ng=m+1;
        while(ng-ok>1){
            int mid=(ok+ng)/2;
            if(asum[i]+bsum[mid]>k) ng=mid;
            else ok=mid;
        }
        ans=max(ans,i+ok);
    }
    cout<<ans<<endl;
    
    
    
}
