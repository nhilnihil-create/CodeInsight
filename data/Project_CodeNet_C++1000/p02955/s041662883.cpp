#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using Map = map<ll,ll>;
using T = tuple<ll,ll,ll>;
using vvl = vector<vector<ll>>;
const ll INF=1LL<<60;
const ll MOD=1000000007;

vector<long long> divisor(long long n) {
vector<long long> ret;
for (long long i = 1; i * i <= n; i++) {
if (n % i == 0) {
ret.push_back(i);
if (i * i != n) ret.push_back(n / i);
}
}
sort(ret.begin(), ret.end()); // 昇順に並べる
return ret;
}

int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    vector<ll> A(N,0);
    ll sum=0;
    for(ll i=0;i<N;i++){
        cin>>A[i];
        sum+=A[i];
    ;}
    vl Y=divisor(sum);
    ll ans=1;
    for(auto p: Y){
        vl B=A;
        for(ll i=0;i<N;i++){
            B[i]%=p;
        ;}
        ll Sum=0;
        for(ll i=0;i<N;i++){
            Sum+=B[i]; 
        ;}
        sort(B.begin(), B.end());
        ll Sum2=0;
        for(ll i=0;i<N;i++){
            Sum2+=B[i];
            if(Sum==p*(N-1-i))break;
        ;}
        if(Sum2<=K)ans=max(ans,p);
    ;}
    cout<<ans<<endl;
    

    return 0;
}
