#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define REP(i,n) for (int64_t i=0; i<(n); ++i)
#define P pair<int,int>
using ll=int64_t;
using namespace std;
#define ketasuu(n) fixed<<setprecision(n)
#define btoe(p) p.begin(),p.end()
#define etob(p) p.rbegin(),p.rend()


const ll inf=4e18+5;

int main(){
    int n,k; cin>>n>>k;
    ll ans=-inf;
    vector<int> p(n); vector<ll> c(n), q;
    rep(i,n) cin>>p[i];
    rep(i,n) cin>>c[i];
    rep(i,n) p[i]--;
    rep(i,n){
        q.clear();
        int now=i;
        do{
            now=p[now];
            q.push_back(c[now]);
            //cout<<c[now]<<endl;
        }while(p[now]!=p[i]);
        ll karians=-inf, tot=0, kari=0;
        for(auto &v: q) tot+=v;
        rep(j,q.size()){
            if(j>=k) break;
            kari+=q[j];
            if(tot>0){
                ll aa=(k-j-1)/q.size();
                if(aa>0){
                    kari+=tot*aa;
                    karians=max(karians,kari);
                    kari-=tot*aa;
                }
            }
            karians=max(karians,kari);
        }
        ans=max(ans,karians);
    }
    cout<<ans<<endl;
    return 0;
}