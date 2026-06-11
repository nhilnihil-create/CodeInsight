#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    int N;
    cin >> N;
    vector<Pll> engine(N);
    rep(i,N){
        ll x,y;
        cin >> x >> y;
        engine[i]=Pll(x,y);
    }
    ll ans=0;
    rep(i,N){
        Pll p=engine[i];
        ll x1=p.first,y1=p.second;
        rep(j,4){
            ll x=y1,y=x1;
            x1=-x,y1=y;
            ll countx=0,county=0;
            ll cx1=0,cx2=0,cy1=0,cy2=0;
            rep(k,N){
                Pll q=engine[k];
                ll x2=q.first,y2=q.second;
                if (x1*x2+y1*y2>0){
                    countx+=x2,county+=y2;
                }
                else if (x1*x2+y1*y2==0){
                    if (x1*y2-x2*y1>0){
                        cx1+=x2,cy1+=y2;
                    }
                    else {
                        cx2+=x2,cy2+=y2;
                    }
                }
            }
            chmax(ans,countx*countx+county*county);
            countx+=cx1,county+=cy1;
            chmax(ans,countx*countx+county*county);
            countx+=cx2-cx1,county+=cy2-cy1;
            chmax(ans,countx*countx+county*county);
        }   
    }
    cout << fixed  << setprecision(10);
    cout << sqrt(ans) << endl;
}