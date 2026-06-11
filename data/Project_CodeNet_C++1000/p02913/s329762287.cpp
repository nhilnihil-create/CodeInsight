#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<string,ll>;
using vl = vector<ll>;
using Map = map<ll,vl>;
using vvl = vector<vector<ll>>;
ll INF=1LL<<60;
ll MOD=998244353;



int main(){
    ll N;
    cin >> N;
    string S;
    cin >> S;
    ll ans=0;
    for(ll i=1;i<N;i++){
        string s=S.substr(0,N-i);
        string t=S.substr(i);
        ll count=0;
        ll Max=0;
        for(ll j=0;j<N-i;j++){
            if(s[j]==t[j])count++;
            else count=0;
            Max=max(count,Max)
        ;}
        Max=min(Max,i);
        ans=max(ans,Max)
    ;}
    cout<<ans<<endl;

    return 0;
}
