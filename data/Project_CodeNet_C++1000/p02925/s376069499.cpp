#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD=1000000007;
vector<vector<ll>> R(550000, vector<ll>(0));//to
vector<ll> Dist(550000, 0);//day
bool visit[550000];
bool calc[550000];

ll id[5050][5050];
 
ll toId(ll i, ll j) {
    if (i > j) swap(i, j);
    return id[i][j];
}
ll dfs(ll u){
    if(visit[u]){
        if(!calc[u])return -1;
        return Dist[u];
    }
    visit[u]=true;
    Dist[u]=1;
    for(ll e: R[u]){
        ll before=dfs(e);
        if(before==-1){return -1;
        }
        Dist[u]=max(Dist[u], before+1);
    }
    calc[u]=true;
    return Dist[u];
}

int main(){
    ll N;
    cin>>N;
    vector<vector<ll>> A(N, vector<ll>(N-1));
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N-1; j++){
            cin>>A[i][j];
            A[i][j] --;
        }
    }
  	 ll V = 0;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            if (i >= j) continue;
            id[i][j] = V++;
        }
    }
    for(ll i=0; i<N; i++){
        for(ll j=0; j<N-2; j++){
           	R[toId(i, A[i][j + 1])].push_back(toId(i, A[i][j]));
        }
    }
    ll Max=0;
    for(ll i=0; i<N*(N-1)/2; i++){//henkou
        ll d=dfs(i);
        if(d==-1){
          cout<<-1<<endl;
          return 0;
        }
        Max=max(Max, d);
    }
    cout<<Max<<endl;
  	return 0;
}