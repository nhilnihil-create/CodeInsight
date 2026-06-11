#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

map<lint,int> p_factorization(lint n){
    map<lint,int> soinsu;
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            n/=i;
            soinsu[i]++;
        }
    }
    if(n!=1)soinsu[n]++;
    return soinsu;
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    lint n;cin>>n;
    int ans=0;
    auto soinsu=p_factorization(n);
    for(auto p:soinsu){
        int kosuu=p.second;
        for(int i=1;i<1000;i++){
            kosuu-=i;
            if(kosuu<0)break;
            ans++;
        }
    }
    cout<<ans<<endl;
}
