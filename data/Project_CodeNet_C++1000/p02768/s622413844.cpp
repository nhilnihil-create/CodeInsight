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

ll modpow(ll a,ll n,ll m){
    ll res=1;
    while(n){
        if(n&1)res=res*a%m;
        a=a*a%m;
        n>>=1;
    }
    return res;
}

const int MAX=510000;

vll finv(MAX);
vll inv(MAX);

void combinit(ll m){
    finv[0]=1;finv[1]=1;
    inv[1]=1;
    rep2(i,2,MAX){
        inv[i]=m-inv[m%i]*(m/i)%m;
        finv[i]=finv[i-1]*inv[i]%m;
    }
}

ll combi2(ll n,ll k){
    ll res=0;ll tmp=(ll)1;
    while(res<k){
        tmp*=n;
        tmp%=inf;
        n--;
        res++;
    }
    return tmp;
}

ll combi(ll n,ll k,ll m){
    if(n<k)return 0;
    if(n<0||k<0)return 0;
    return (combi2(n,k)*finv[k])%m;
}

int main(){
    ll n,a,b;cin>>n>>a>>b;
    combinit(inf);
    ll tmp=modpow((ll)2,n,inf)-combi(n,a,inf)-combi(n,b,inf)-(ll)1;
    while(tmp<0)tmp+=inf;
    cout<<tmp<<endl;
}