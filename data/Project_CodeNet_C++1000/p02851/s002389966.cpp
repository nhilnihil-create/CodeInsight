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
const ll inf=1e9+7;
const ll mod=1e9+7;
int main(){
    ll n,k;cin>>n>>k;
    vector<ll>a(n+1);
    map<ll,ll>m;
    REP(i,1,n+1){
        ll b;cin>>b;
        a[i]=a[i-1]+b;
    }
    ll ans=0;
    rep(i,n+1){
        if(i>=k){
            ll s=a[i-k]-(i-k);
            s%=k;
            if(s<0)s+=k;
            m[s]--;
        }
        ll s=a[i]-i;
        s%=k;
        if(s<0)s+=k;
        ans+=m[s];
        m[s]++;
    }
    cout<<ans<<endl;
}