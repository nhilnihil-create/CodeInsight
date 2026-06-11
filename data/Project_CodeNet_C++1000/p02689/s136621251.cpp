#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define rep(i,l,r) for (ll i = (ll)l; i < (ll)(r); i++)

int main(){
    int N,M; cin >> N >> M;
    vector<int> H(N);
    vector<priority_queue<int> > G(N+1);
    rep(i,0,N) cin >> H[i];
    rep(i,0,M){
        int a,b; cin >> a >> b;
        a--; b--;
        G[a].push(H[b]);
        G[b].push(H[a]);
    }
    int ans=0;
    rep(i,0,N){
        if(G[i].empty()){
            ans++;
            continue;
        }
        if(G[i].top() < H[i]) ans++;
    }
    
    cout << ans << endl;
}