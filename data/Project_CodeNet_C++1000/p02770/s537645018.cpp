#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
#define REP(i,m,n) for(int i=(m);i<(n);i++)
#define rep(i,n) REP(i,0,n)
#define pb push_back
#define all(a) a.begin(),a.end()
#define rall(c) (c).rbegin(),(c).rend()
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll k,q;cin>>k>>q;
    vector<ll>d(k+1);
    rep(i,k)cin>>d[i+1];
    while(q){
        q--;
        ll n,x,m;cin>>n>>x>>m;
        vector<ll>a(k+1);
        vector<ll>b(k+1);
        REP(i,1,k+1){
            a[i]=a[i-1]+d[i]%m;
            if(d[i]%m)b[i]=b[i-1]+1;
            else b[i]=b[i-1];
        }
        n--;
        ll ans=n/k*b[k]+b[n%k];
        ll cnt=x%m+n/k*a[k]+a[n%k];
        ans-=cnt/m;
        cout<<ans<<endl;
    }
}