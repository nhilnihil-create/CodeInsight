#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#include <boost/multiprecision/cpp_ll.hpp>
//typedef boost::multiprecision::cpp_ll ll;
typedef long double dd;
#define i_7 (ll)(1E9+7)
//#define i_7 998244353
#define i_5 i_7-2
ll mod(ll a){
    ll c=a%i_7;
    if(c>=0)return c;
    return c+i_7;
}
typedef pair<ll,ll> l_l;
ll inf=(ll)1E16;
#define rep(i,l,r) for(ll i=l;i<=r;i++)
#define pb push_back
ll max(ll a,ll b){if(a<b)return b;else return a;}
ll min(ll a,ll b){if(a>b)return b;else return a;}
void Max(ll &pos,ll val){pos=max(pos,val);}//Max(dp[n],dp[n-1]);
void Min(ll &pos,ll val){pos=min(pos,val);}
void Add(ll &pos,ll val){pos=mod(pos+val);}
dd EPS=1E-9;
string alp="abcdefghijklmnopqrstuvwxyz";
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

struct Node{
    bool seen[3];
    vector<ll> to;
};

int main(){
    ll n,m;cin>>n>>m;
    ll v,u;
    Node node[n+1];
    rep(i,1,n){
        rep(j,0,2){
            node[i].seen[j]=false;
        }
    }
    rep(i,0,m-1){
        cin>>v>>u;
        node[v].to.pb(u);
        //node[u].to.pb(v);
    }
    queue<pair<ll,ll>> q;
    ll s,t;cin>>s>>t;
    q.push(make_pair(0,s));
    while(q.size()>0){
        ll flag=q.front().first;
        ll x=q.front().second;
        q.pop();
        if(flag%3==0 && x==t){
            cout<<flag/3<<endl;
        }
        if(node[x].to.size()!=0){
        rep(j,0,node[x].to.size()-1){
            if(node[node[x].to[j]].seen[(flag+1)%3]){
                continue;
            }
            node[node[x].to[j]].seen[(flag+1)%3]=true;
            q.push(make_pair(flag+1,node[x].to[j]));
        }
        }
    }
    if(node[t].seen[0]){
        
    }else{
        cout<<-1<<endl;
    }
    
    return 0;
}


