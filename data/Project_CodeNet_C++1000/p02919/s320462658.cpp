#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    vector<ll> P(N,0);
    Map where;
    for(ll i=0;i<N;i++){
        cin>>P[i];
        where[P[i]]=i;
    ;}

    ll ans=0;
    
    //Sにでかい順に格納
    multiset<ll> S;
    S.insert(-1);
    S.insert(-1);
    S.insert(N);
    S.insert(N);
    ll e=0;

    //一つずつ真の値に変えていく
    for(ll i=N;i>=1;i--){
        ll k=where[i];
        S.insert(k);
        ll a,b,c,d,y,x;
        auto t=S.lower_bound(k);
        auto p=t,q=t,r=t,s=t;
        p--;p--;q--;r++;s++;s++;

        ans+=(*q-*p)*(*r-k)+(k-*q)*(*s-*r);
        e+=ans;
    }

    cout<<e<<endl;

    return 0;
}
