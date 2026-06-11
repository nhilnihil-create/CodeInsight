#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    if(n==2){
        ll x,y;cin>>x>>y;
        if(x>y)swap(x,y);
        ll res=y-x;
        cout<<res<<endl;
        cout<<y<<" "<<x<<endl;
        return 0;
    }
    vector<ll> b,c;
    rep(i,n){
        ll a;cin>>a;
        if(a>0)b.push_back(a);
        else c.push_back(a);
    }
    vector<pair<ll,ll>> p;
    ll res=0;
    if(b.size()==0){
        sort(c.begin(),c.end());
        res=c[n-1]-c[0];
        p.push_back({c[n-1],c[0]});
        rep(i,n-2){
            p.push_back({res,c[i+1]});
            res-=c[i+1];
        }
    }else{
        if(b.size()==n){
            sort(b.begin(),b.end());
            res=b[n-1]-b[0];
            p.push_back({b[0],b[n-1]});
            rep(i,n-3){
                p.push_back({-res,b[i+1]});
                res+=b[i+1];
            }
            p.push_back({b[n-2],-res});
            res+=b[n-2];
        }else{
            res=b[0];
            rep(i,b.size()-1){
                p.push_back({c[0],b[i+1]});
                c[0]-=b[i+1];
            }
            rep(i,c.size()){
                p.push_back({res,c[i]});
                res-=c[i];
            }
        }
    }
    cout<<res<<endl;
    rep(i,n-1)cout<<p[i].first<<" "<<p[i].second<<endl;
}