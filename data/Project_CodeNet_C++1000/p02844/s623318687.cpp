#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define P pair<ll,ll>
#define Graph vector<vector<ll>>
#define INF (1ll<<60)
#define mod 998244353
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;} return false;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;} return false;}

int main(){
    ll n;cin>>n;
    string s;cin>>s;
    
    ll ans=0;
    vector<bool> check(1000,false);
    
    rep(i,1000){
        ll f=i/100,se=(i/10)%10,t=i%10;
        bool okf=false,okse=false,okt=false;
        rep(j,n){
            if(okse && t==(ll)(s[j]-'0')){
                okt=true;
            }
            if(okf && se==(ll)(s[j]-'0')){
                okse=true;
            }
            if(f==(ll)(s[j]-'0')){
                okf=true;
            }
        }
        if(okt){
            check[i]=true;
        }
    }

    rep(i,1000){
        if(check[i]==true) ans++;       
    }

    cout<<ans<<endl;
    return 0;
}