#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<typename T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<typename T>inline auto vec2(typename vector<T>::size_type h,typename vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}

int main()
{
    ll x=in(),y=in();
    ll m[]={300000,200000,100000};
    cout<<(x<=3?m[x-1]:0)+(y<=3?m[y-1]:0)+(x==1&&y==1?400000:0)<<endl;
}
