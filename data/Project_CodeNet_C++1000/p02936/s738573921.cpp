#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll INF=1LL<<60;
const int MOD=1e9+7;

vector<vi> G;
vector<bool> visit;
vi cnt;

void dfs(int v, int sum){
    visit[v]=true;
    for(auto nv : G[v]){
        if(visit[nv]) continue;
        dfs(nv, sum+cnt[v]);
    }
    cnt[v]+=sum;
}

int main(){
    int N, Q; cin >> N >> Q;
    G.resize(N);
    visit.assign(N, 0);
    cnt.resize(N, 0);
    for(int i=0; i<N-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for(int i=0; i<Q; i++){
        int p, x; cin >> p >> x;
        cnt[p-1]+=x;
    }
    dfs(0, 0);
    for(int i=0; i<N; i++){
        if(i != 0) cout << " "; 
        cout << cnt[i];
    }
    cout << endl;
    return 0;
}

