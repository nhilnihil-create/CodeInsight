#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pp pair<pair<ll, ll>,pair<ll, ll>>
#define pll pair<ll,ll>
#define pdd pair<double,double>
#define vii vector<int>
#define vll vector<ll>
#define mat vector<vector<ll>>
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define fi first
#define sc second
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep2(i,a,b) for(ll i=a;i<b;i++)
#define repr(i,n) for(ll i=n-1;i>=0;i--)
#define all(x) x.begin(),x.end()
#define sz(x) (ll) (x).size()
#define pq priority_queue<ll>
#define pqg priority_queue<ll,vector<ll>,greater<ll>>
#define LB(v,x) (lower_bound(v.begin(),v.end(),x)-v.begin())
#define UB(v,x) (upper_bound(v.begin(),v.end(),x)-v.begin())
#define ERASE(v) sort(v.begin(),v.end());v.erase(unique(v.begin(),v.end()),v.end())
#define int ll
// #define ll int
using namespace std;
const ll INF = (1 << 30 ) - 1;
const ll LLINF = (1LL << 60LL);
const ll MOD = 1000000007;
// const ll mod = 998244353;
const ll MAX = 2100000;
const double pi = acos(-1);
const double eps = 1e-10;
ll dx[8] ={1,0,-1,0,1,-1,1,-1};
ll dy[8] ={0,1,0,-1,1,-1,-1,1};
 
template<class T> 
inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> 
inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }




bool compare(pll &a, pll &b){
    if(a.fi!=b.fi) return a.fi>b.fi;
    else return a.sc<b.sc;
}


void solve(){
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<pll> p,q,r;
    rep(i,a){
        ll s;cin>>s;
        p.pb({s,-1});
    }
    rep(i,b){
        ll s;cin>>s;
        q.pb({s,-1});
    }
    ll d[200010];
    rep(i,c){
        cin>>d[i];
    }
    sort(d,d+c);reverse(d,d+c);
    rep(i,c){
        r.pb({d[i],i});
        p.pb({d[i],i});
        q.pb({d[i],i});
    }
    sort(all(p),compare);
    sort(all(q),compare);
    priority_queue<ll> que;
    ll ans=0;
    ll cnt[100010]={};
    rep(i,x){
        ans+=p[i].fi;
        if(p[i].sc!=-1) cnt[p[i].sc]++;
    }
    rep2(i,x,(ll)p.size()){
        if(p[i].sc==-1) que.push(p[i].fi);
    }
    rep(i,y){
        ans+=q[i].fi;
        if(q[i].sc!=-1) cnt[q[i].sc]++;
    }
    rep2(i,y,(ll)q.size()){
        // cout<<q[i].fi<<" "<<q[i].sc<<endl;
        if(q[i].sc==-1) que.push(q[i].fi);
    }
    rep(i,c){
        if(cnt[i]==0){
            que.push(d[i]);
        }
    }
    rep(i,c){
        if(cnt[i]==2){
            ans-=d[i];
            ans+=que.top();
            que.pop();
        }
    }
    cout<<ans<<endl;

}



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(15);


    solve(); 


    return 0;
}
