#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vin=vector<int>;
using vll=vector<long long>;
using vvin=vector<vector<int>>;
using vvll=vector<vector<long long>>;
using vstr=vector<string>;
using vvstr=vector<vector<string>>;
using vch=vector<char>;
using vvch=vector<vector<char>>;
using vbo=vector<bool>;
using vvbo=vector<vector<bool>>;
using vpii=vector<pair<int,int>>;
using pqsin=priority_queue<int,vector<int>,greater<int>>;
#define mp make_pair
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i=(s);i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const ll inf=1e9+7;
const ll INF=1e18;

int main(){
    int n,d;ll a;cin>>n>>d>>a;
    map<int,ll> fox;
    vin x(n);
    ll h;
    rep(i,n){
        cin>>x[i]>>h;
        fox[x[i]]=h;
    }
    sort(all(x));
    vll bom(n+1);
    ll ans=(ll)0,tmp;
    rep(i,n){
        if(i>0)bom[i]+=bom[i-1];
        fox[x[i]]-=bom[i];
        if(fox[x[i]]<=0)continue;
        tmp=(fox[x[i]]+a-(ll)1)/a;
        ans+=tmp;
        bom[i]+=tmp*a;
        bom[upper_bound(all(x),x[i]+2*d)-x.begin()]-=tmp*a;
    }
    cout<<ans<<endl;
}