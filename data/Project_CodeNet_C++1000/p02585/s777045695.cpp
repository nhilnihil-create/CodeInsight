#include<iostream>
#include<iomanip>
#include<cassert>
#include<math.h>
#include<complex>
#include<algorithm>
#include<utility>
#include<queue>
#include<string.h>
#include<string>
#include<set>
#include<map>
#include<unordered_map>
#include<functional>
#include<vector>
using namespace std;
typedef long long ll;
const ll INF=2e18;
const ll MOD=1e9+7;

ll N,K;
ll P[5010];
ll C[5010];
ll CircleStart(ll s){
    ll n=s;
    bool f[5010]={};
    f[s]=true;
    for(ll cnt=0;cnt<N;cnt++){
        n=P[n];
        if(f[n]) return n;
        f[n]=true;
    }
    return -1;
}
vector<ll> CircleVec(ll s){
    vector<ll> ret;
    ll n=P[s];
    ll nCost=C[n];
    while(n!=s){
        ret.push_back(nCost);
        n=P[n];
        nCost+=C[n];
    }
    ret.push_back(nCost);
    return ret;
}
ll CircleBest(ll s,ll k){
    vector<ll> v=CircleVec(s);
    ll circleCost=v[v.size()-1];
    ll ret=-INF;
    if(circleCost>0){
        ll circleSize=v.size();
        ll tmp=0;
        for(ll i=1;i<=min(k,(ll)v.size());i++){
            if(k%circleSize >= i){
                tmp = k/circleSize * circleCost;
            }else{
                tmp = (k/circleSize -1) * circleCost;
            }
            ret=max(ret,tmp+v[i-1]);
        }
    } else{
        for(ll i=1;i<=min(k,(ll)v.size());i++){
            ret=max(ret,v[i-1]);
        }
    }
    return ret;
}

ll Calc(ll s,ll k){
    ll circleStart=CircleStart(s);
    if(circleStart!=s){
        ll now=s;
        ll nCost=0;
        ll ret=-INF;
        while(now!=circleStart){
            k--;
            now=P[now];
            nCost+=C[now];
            ret=max(ret,nCost);
        }
        return max(ret,nCost+CircleBest(now,k));
    }
    return CircleBest(s,k);
}

int main(){
    cin>>N>>K;
    for(ll i=1;i<=N;i++)cin>>P[i];
    for(ll i=1;i<=N;i++)cin>>C[i];
    ll ans=-INF;
    for(ll i=1;i<=N;i++){
        ans=max(ans,Calc(i,K));
    }
    cout<<ans<<endl;
    return 0;
}