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

ll modpow(ll a,ll n,ll m=inf){
    ll res=1;
    while(n){
        if(n&1)res=res*a%m;
        a=a*a%m;
        n>>=1;
    }
    return res;
}

int main(){
    ll n,k;cin>>n>>k;
    vll num(k+1);
    ll ans=(ll)0,res,sum;
    for(ll i=k;i>0;i--){
        res=k/i;
        sum=modpow(res,n);
        for(ll j=2*i;j<=k;j+=i){
            sum-=num[j];
            if(sum<0)sum+=inf;
        }
        num[i]=sum;
        ans+=i*sum;ans%=inf;
    }
    cout<<ans<<endl;
}