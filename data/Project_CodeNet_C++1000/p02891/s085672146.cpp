#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define sz(x) int(x.size())
#define pb push_back
#define eb emplace_back
using ll=long long;
using P = pair<int,int>;
using LP=pair<ll,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
const ll MOD=1000000007,MOD2=998244353;



int main() {
    string S;
    ll K;
    cin>>S>>K;
    bool judge=true;
    rep(i,sz(S)-1){
        if(S.at(i)!=S.at(i+1))judge=false;
    }
    if(judge){
        ll x=K;
        x*=sz(S);
        cout<<x/2<<endl;
        return 0;
    }
    string S2=S+S;
    if(sz(S)==1){cout<<max(K-2,0ll)<<endl;return 0;}
    int count1=0,count2=0;
    rep(i,sz(S)-1){
        if(S.at(i)==S.at(i+1)){
            S.at(i+1)='!';
            count1++;
        }
    }
    
    rep(i,sz(S2)-1){
        if(S2.at(i)==S2.at(i+1)){
            S2.at(i+1)='!';
            count2++;
        }
    }
    ll ans=count2-count1;
    ans*=K-1;
    ans+=count1;
    cout<<ans<<endl;
}