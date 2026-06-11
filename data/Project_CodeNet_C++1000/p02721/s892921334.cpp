#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
#define rep(cnt,e) for(ll cnt=0;cnt<e;cnt++ )
typedef pair<ll,ll> P;
const ll mod = 1e9+7;
const ll INF = INT64_MAX;

ll i,j,k;

int main(){
    ll N,K,C;
    cin>>N>>K>>C;
    string S;
    cin>>S;

    vector<ll> saki,ato;

    ll cnt=0;
    ll ka=0;
    while(cnt<N&&ka<K){
        if(S[cnt]=='o'){
            saki.push_back(cnt);
            cnt+=C+1;
            ka++;
        }
        else{
            cnt++;
        }
    }
    cnt=0;
    ka=0;
    while(cnt<N&&ka<K){
        if(S[N-1-cnt]=='o'){
            ato.push_back(N-1-cnt);
            cnt+=C+1;
            ka++;
        }
        else{
            cnt++;
        }
    }
    sort(saki.begin(),saki.end());
    sort(ato.begin(),ato.end());
    rep(i,K)if(saki[i]==ato[i])cout<<saki[i]+1<<endl;
    
}