#include<bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define debug(v) cout<<#v<<":";for(auto x:v){cout<<x<<' ';}cout<<endl;
#define INF 1000000000
#define mod 1000000007
using ll=long long;
const ll LINF=1001002003004005006ll;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
// ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
template<class T>bool chmax(T &a,const T &b){if(a<b){a=b;return true;}return false;}
template<class T>bool chmin(T &a,const T &b){if(b<a){a=b;return true;}return false;}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int n,m;cin>>n>>m;
    vector<vector<ll>> v(m);
    rep(i,n){
        ll a,b;cin>>a>>b;
        if(m-a<0) continue;
        v[m-a].push_back(b);
    }
    priority_queue<ll> que;
    ll ans=0;
    for(int i=m-1;i>=0;i--){
        for(auto x:v[i]){
            que.push(x);
        }
        if(que.empty()) continue;
        ans+=que.top();que.pop();
    }
    cout<<ans<<endl;
    return 0;
}
