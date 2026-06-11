//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    ll n,k,ans=1; cin>>n>>k;
    vector<vector<int>> path(n);
    rep(i,n-1){
        int a,b; cin>>a>>b;
        a--; b--;
        path[a].push_back(b);
        path[b].push_back(a);
    }
    ll r=0;
    rep(i,n) r=max(r,(ll)path[i].size()+1);
    if(k<r){
        cout<<0<<endl;
        return 0;
    }
    queue<pair<ll,ll>> que;
    que.push(mk(0,-1));
    ll s,par;
    vector<ll> visited(n,0);
    vector<ll> used(n,0);
    while(!(que.empty())){
        tie(s,par)=que.front();
        que.pop();
        visited[s]=1;
        if(par==-1){
            used[s]=1;
            ans=(ans*k)%MOD;
            for(auto to:path[s])
            que.push(mk(to,s));
        }
        else{
            ans=(ans*(k-used[par]))%MOD;
            used[par]++;
            used[s]=2;
            for(auto to:path[s])if(to!=par)
            que.push(mk(to,s));
        }
    }
    cout<<ans<<endl;
}