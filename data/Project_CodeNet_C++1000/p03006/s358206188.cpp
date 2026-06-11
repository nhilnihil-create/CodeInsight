#include"bits/stdc++.h"
using namespace std;
using ll=long long;
using ull=unsigned long long;
constexpr auto inf=static_cast<ll>(1e18);
template<typename T=ll>inline T in(){T ret;cin>>ret;return ret;}
template<typename T=ll>inline auto vec2(size_t h,size_t w,T v=T()){return vector<vector<T>>(h,vector<T>(w,v));}
inline void setp(int n){cout<<fixed<<setprecision(n);}
inline void delnl(){cin.ignore(numeric_limits<streamsize>::max(),'\n');}

class union_find{
    private:
        vector<ll>par,sz,rank;
        ll cnt;
    public:
        union_find  (ll n):par(n),sz(n,1),rank(n,0),cnt(n){iota(par.begin(),par.end(),0);}
        ll   count  ()          {return cnt;}
        ll   find   (ll n)      {return par[n]==n?n:par[n]=find(par[n]);}
        ll   size   (ll n)      {return sz[find(n)];}
        bool is_same(ll x, ll y){return find(x)==find(y);}
        void unite  (ll x, ll y)
        {
            x=find(x);y=find(y);
            if(x!=y){
                if(rank[x]<rank[y]){
                    par[x]=y;
                    sz[y]+=sz[x];
                }else{
                    par[y]=x;
                    sz[x]+=sz[y];
                    if(rank[x]==rank[y])++rank[x];
                }
                --cnt;
            }
        }
};
pair<ll,ll>get_unique_dist_vec(const pair<ll,ll>&p1,const pair<ll,ll>&p2)
{
    ll dx=p2.first-p1.first;
    ll dy=p2.second-p1.second;
    if(dx<0){dx*=-1;dy*=-1;}
    else if(dx==0)dy=abs(dy);
    return {dx,dy};
}
int main()
{
    ll n=in();
    vector<pair<ll,ll>>cood(n);
    for(ll i=0;i<n;++i){
        cood[i].first=in();
        cood[i].second=in();
    }

    set<pair<ll,ll>>tang;
    for(ll i=0;i<n;++i){
        for(ll j=i+1;j<n;++j){
            tang.emplace(get_unique_dist_vec(cood[i],cood[j]));
        }
    }

    ll ans=n;
    for(const auto&t:tang){
        union_find uf(n);
        for(ll i=0;i<n;++i){
            for(ll j=i+1;j<n;++j){
                if(t==get_unique_dist_vec(cood[i],cood[j])){
                    uf.unite(i,j);
                }
            }
        }
        ans=min(ans,uf.count());
    }
    cout<<ans<<endl;
}
