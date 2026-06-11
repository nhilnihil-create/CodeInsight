#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int N,D,A,X[201010],H[201010];
ll buf[201010];

int main(){
    cin>>N>>D>>A;
    rep(i,N) cin>>X[i]>>H[i];
    D*=2;
    vector<pair<int,int>> xh;
    rep(i,N) xh.push_back({X[i],H[i]});
    sort(all(xh));

    ll ans=0;
    int R=0;
    rep(L,N){
        if(L) buf[L]+=buf[L-1];
        int x=xh[L].first;
        int h=xh[L].second;

        if(buf[L]<h){
            R=max(R,L+1);
            while(R<N && xh[R].first-x<=D) R++;

            ll d=h-buf[L];
            ll cnt=(d+A-1)/A;

            buf[L]+=cnt*A;
            buf[R]-=cnt*A;
            ans+=cnt;
        }
    }

    cout<<ans<<endl;
}