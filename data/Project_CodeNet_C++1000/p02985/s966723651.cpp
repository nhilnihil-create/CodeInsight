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

vector<ll> v[100001];
struct Node{
    ll par;
    vector<ll> chi;
};
Node node[100001];
vector<ll> bro;
ll bro1;
void hoge(ll i){
    ll sum=0;
    rep(j,0,v[i].size()-1){
        if(v[i][j]!=node[i].par){
            node[i].chi.pb(v[i][j]);
            node[v[i][j]].par=i;
            sum++;
            hoge(v[i][j]);
        }
    }
    if(i==1){
        bro1=sum;
    }else if(sum>0){
        bro.pb(sum);
    }
}

ll kai(ll i,ll j){
    ll sum=1;
    rep(ii,0,j-1){
        sum=(sum*(i-ii))%i_7;
    }
    return sum;
}


int main(){
    ll n,k;cin>>n>>k;
    ll a[n-1],b[n-1];
    if(n==1){
        cout<<k<<endl;
        return 0;
    }
    rep(i,0,n-2){
        cin>>a[i]>>b[i];
        v[a[i]].pb(b[i]);
        v[b[i]].pb(a[i]);
    }
    node[1].par=1;
    hoge(1);
    ll ans=k%i_7;
    ans=(ans*kai(k-1,bro1))%i_7;
    if(bro.size()>0){
        rep(i,0,bro.size()-1){
            ans=(ans*kai(k-2,bro[i]))%i_7;
        }
    }
    cout<<ans<<endl;
    
    
    
    return 0;
}


