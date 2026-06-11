#define _GLIBCXX_DEBUG
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
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
#define rep2(i,s,n) for(ll i=(s);i<(ll)(n);i++)
#define all(v) v.begin(),v.end()
#define decp(n) cout<<fixed<<setprecision((int)n)
const int inf=1e9+7;
const ll INF=1e18;

int main(){
    int v,e,r;cin>>v>>e>>r;
    vector<tuple<int,int,int>> edge(e);
    vin d(v,inf);
    rep(i,e){
        int s,t,w;cin>>s>>t>>w;
        edge[i]=make_tuple(s,t,w);
    }
    d[r]=0;
    bool update;
    int res=0;
    while(1){
        res++;
        update=false;
        for(auto hen:edge){
            if(d[get<0>(hen)]!=inf&&d[get<1>(hen)]>d[get<0>(hen)]+get<2>(hen)){
                d[get<1>(hen)]=d[get<0>(hen)]+get<2>(hen);
                update=true;
            }
        }
        if(!update)break;
        if(res==v){
            cout<<"NEGATIVE CYCLE"<<endl;
            return 0;
        }
    }
    rep(i,v){
        if(d[i]==inf)cout<<"INF"<<endl;
        else cout<<d[i]<<endl;
    }
}
