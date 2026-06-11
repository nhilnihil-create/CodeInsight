#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    ll D;
    cin >> D;
    ll A;
    cin >> A;
    vector<P> vec(N);
    for(ll i=0;i<N;i++){
        ll x;
        cin >> x;
        ll h;
        cin >> h;
        vec[i]=P(x,h);
    ;}
    sort(vec.begin(), vec.end());
    vector<ll> until(N,INF);
    until[0]=0;
    for(ll i=0;i<N;i++){
        if(i>0){
            //既に爆破された回数
            ll b=until[i-1];
            if(vec[i].first>vec[0].first+2*D)
            b-=until[lower_bound(vec.begin(), vec.end(), P(vec[i].first-2*D,-INF))-1-vec.begin()];
            vec[i].second-=b*A;
            until[i]=until[i-1];
        }
        if(vec[i].second>0){
            until[i]+=vec[i].second/A;
            vec[i].second-=(vec[i].second/A)*A;
            if(vec[i].second>0){vec[i].second-=A;until[i]++;}
        }
    ;}
    cout<<until[N-1]<<endl;

    return 0;
}
