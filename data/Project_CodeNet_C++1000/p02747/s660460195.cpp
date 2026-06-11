#include"bits/stdc++.h"
using namespace std;
using ll=long long;
template<class T=ll>inline T in(istream&is=cin){T ret;is>>ret;return ret;}
template<class T>inline auto vec2(class vector<T>::size_type h,class vector<T>::size_type w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
template<class RandomAccessIterator>inline void psortb(RandomAccessIterator first,RandomAccessIterator last){using P=pair<decltype(first->first),decltype(first->second)>;sort(first,last,[](const P&p1,const P&p2){return p1.second<p2.second||(p1.second==p2.second&&p1.first<p2.first);});}

int main()
{
    string s;cin>>s;
    string foo="hi";
    for(ll i=0;i<5;++i){
        if(s==foo){
            cout<<"Yes"<<endl;
            return 0;
        }
        foo+="hi";
    }
    cout<<"No"<<endl;
}
