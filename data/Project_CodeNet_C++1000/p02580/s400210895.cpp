#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int H,W,M; cin >> H >> W >> M;
    vector<ll> maxh(H,0);
    vector<ll> maxw(W,0);
    ll h[M],w[M];
    ll max_cnth=0;
    ll max_cntw=0;
    for(int i=0;i<M;i++){
        cin >> h[i] >> w[i]; h[i]--; w[i]--;
        maxh[h[i]]++;
        maxw[w[i]]++;
        max_cnth=max(max_cnth,maxh[h[i]]);
        max_cntw=max(max_cntw,maxw[w[i]]);
    }
    map<int,ll> ish;
    map<int,ll> isw;
    ll cnth=0; ll cntw=0;
    for(int i=0;i<H;i++){
        if(maxh[i]==max_cnth){
            ish[i]++; cnth++;
        }
    }
    for(int i=0;i<W;i++){
        if(maxw[i]==max_cntw){
            isw[i]++; cntw++;
        }
    }
    ll cnt=0;
    for(int i=0;i<M;i++){
        if(ish[h[i]]&&isw[w[i]]) cnt++;
    }
    ll sum=cnth*cntw;
    if(sum>cnt){
        cout << max_cnth+max_cntw << endl;
    }else{
        cout << max_cnth+max_cntw-1 << endl;
    }
}