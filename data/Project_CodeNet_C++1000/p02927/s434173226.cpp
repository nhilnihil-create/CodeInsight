#include"bits/stdc++.h"
using namespace std;
using ll=long long;
using ull=unsigned long long;
constexpr auto inf=static_cast<ll>(1e18);
template<typename T=ll>inline T in(){T ret;cin>>ret;return ret;}
template<typename T=ll>inline auto vec2(size_t h,size_t w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
inline void setp(int n){cout<<fixed<<setprecision(n);}
inline void delnl(){cin.ignore(numeric_limits<streamsize>::max(),'\n');}

int main()
{
    ll m=in(),d=in();
    ll cnt=0;
    for(ll i=1;i<=m;++i){
        for(ll j=1;j<=d;++j){
            ll d1=j%10,d10=j/10;
            if(d1>=2&&d10>=2&&d1*d10==i)++cnt;
        }
    }
    cout<<cnt<<endl;
}