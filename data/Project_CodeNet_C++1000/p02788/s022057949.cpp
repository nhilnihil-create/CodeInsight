#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;

int main(){
    ll n,d,a;
    cin>>n>>d>>a;
    vector<P>xh(n);
    rep(i,n){
        ll x,h; cin>>x>>h;
        xh[i]=P(x,h);
    }
    sort(xh.begin(),xh.end());
    queue<P>q;
    ll bomb=0,ans=0;
    rep(i,n){
        //範囲外の爆弾の数を引く
        while(!q.empty()&&q.front().first<xh[i].first){
            bomb-=q.front().second;
            q.pop();
        }
        //当たってる分hp減らす
        xh[i].second-=bomb*a;
        //今回使う回数
        ll use=(xh[i].second+a-1)/a;
        if(use<=0)continue;
        ans+=use;
        bomb+=use;
        q.push(P(xh[i].first+2*d,use));
    }
    cout<<ans<<endl;
}