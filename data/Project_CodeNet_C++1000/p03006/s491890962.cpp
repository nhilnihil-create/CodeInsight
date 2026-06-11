#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
#define all(v) v.begin(), v.end()
#define print(v) cout<<v<<endl;
#define first(v) get<0>(v)
#define second(v) get<1>(v)
#define third(v) get<2>(v)
template <typename T> bool chmax(T &a, const T &b){if (a<b){a=b;return 1;}return 0;}
template <typename T> bool chmin(T &a, const T &b){if (a>b){a=b;return 1;}return 0;}
const ll INF=1LL<<60;
const ll MOD=1000000007;


int main(){
    ll N;
    cin >> N;
    vector<ll> X(N,0);
    vector<ll> Y(N,0);
    for(ll i=0;i<N;i++){
        cin>>X[i]>>Y[i]
    ;}  
    ll ans=0;
    for(ll i=0;i<N;i++){
       for(ll j=0;j<N;j++){
           if(i==j)continue;
           ll p=X[i]-X[j];
           ll q=Y[i]-Y[j];
           ll count=0;
           for(ll k=0;k<N;k++){
              for(ll l=0;l<N;l++){
                  if(X[k]-X[l]==p&&Y[k]-Y[l]==q)count++;
              ;}
           ;}
           chmax(ans,count);
       ;}
    ;}
    print(N-ans)

    return 0;
}
