// ABC156-D
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int num=210000;
ll mod=pow(10,9)+7;
vector<ll> fact(num);
vector<ll> invfact(num);
ll modpow(ll x,ll y,ll mod){ //x^y
    if(y==0) return 1;
    if(y==1) return x%mod;
    if(y%2==1) return x*modpow(x,y-1,mod)%mod;
    ll t=modpow(x,y/2,mod);
    return (t*t)%mod;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n,a,b;
    cin>>n>>a>>b;
    fact[0]=1;
    for(int i=1;i<num;i++){
        fact[i]=fact[i-1]*i%mod;
    }
    invfact[num-1]=modpow(fact[num-1],mod-2,mod);
    for(int i=num-2;i>-1;i=i-1){
        invfact[i]=invfact[i+1]*(i+1)%mod;
    }
    ll ans=modpow(2,n,mod)-1;
    //cout<<ans<<endl;
    ll npa=1,npb=1;
    for(int i=0;i<a;i++){
        npa=npa*(n-i)%mod;
    }
    npa=npa*invfact[a]%mod;

    for(int i=0;i<b;i++){
        npb=npb*(n-i)%mod;
    }
    npb=npb*invfact[b]%mod;
    ans=ans-(npa+npb)%mod;
    //cout<<ans<<endl;
    ans%=mod;
    if(ans<0) ans+=mod;
    cout<<ans<<endl;
    //cout<<npa<<" "<<npb<<endl;
    // cout<<invfact[a]<<" "<<invfact[b]<<endl;
    return 0;
}