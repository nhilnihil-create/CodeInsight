// ABC145-D
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define e_b emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ipair;
typedef pair<ll,ll> lpair;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v) //vectorの中身を見る
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
void map_p(map<int,int>& d){cout<<"map: ";for(auto a : d){cout<<"{"<<a.first<<":"<<a.second<<"}";}cout<<endl;} //mapの中身を見る
void set_p(set<int>& d){cout<<"set: ";for(int a : d){cout<<a<<" ";}cout<<endl;} //setの中身を見る

ll modpow(ll x,ll y,ll mod){
    if(y==0) return 1;
    if(y==1) return x%mod;
    if(y%2==1) return x*modpow(x,y-1,mod)%mod;
    ll t=modpow(x,y/2,mod);
    return t*t%mod;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    ll x,y;
    ll mod=pow(10,9)+7;
    cin>>x>>y;
    if((2*x-y)%3==0){
        ll b=(2*x-y)/3;
        ll a=x-2*b;
        if(a>=0 && b>=0){
            vector<ll> fact(a+b+10,0);
            fact[0]=1;
            for(int i=1;i<=a+b;i++){
                fact[i]=fact[i-1]*i%mod;
            }
            vector<ll> invfact(a+b+10,0);
            invfact[a+b]=modpow(fact[a+b],mod-2,mod);
            for(int i=a+b-1;i>=0;i=i-1){
                invfact[i]=invfact[i+1]*(i+1)%mod;
            }
            ll ans=fact[a+b]*invfact[a]%mod*invfact[b]%mod;
            cout<<ans<<endl;
        }else cout<<0<<endl;
    }else cout<<0<<endl;
    return 0;
}