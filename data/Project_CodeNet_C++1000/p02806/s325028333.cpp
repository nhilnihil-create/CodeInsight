#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<typename T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<typename T>inline auto vec2(typename vector<T>::size_type h,typename vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}

int main()
{
    ll n=in();
    vector<pair<string,ll>>st(n);
    for(int i=0;i<n;++i){
        string s;cin>>s;
        st[i]={s,in()};
    }
    string x;cin>>x;
    ll ans=0;
    bool f=false;
    for(int i=0;i<n;++i){
        if(f)ans+=st[i].second;
        f|=st[i].first==x;
    }
    cout<<ans<<endl;
}
