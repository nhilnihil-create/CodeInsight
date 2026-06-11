#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
vector<pair<int,int>> to[100010];
vector<int> ans(100010,0);

void bfs(int now,int p,int col){
    int k = 1;
    for(auto u : to[now]){
        if(u.first==p) continue;
        if(k==col) k++;
        ans[u.second] = k;
        bfs(u.first,now,k);
        k++;
    }
}

int main(){
    int n;
    cin >> n;
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back({b,i});
        to[b].push_back({a,i});
    }
    int max_size=0;
    rep(i,n) max_size = max(max_size,(int)to[i].size());
    bfs(0,-1,-1);
    cout<<max_size<<endl;
    rep(i,n-1){
        cout<<ans[i]<<endl;
    }
    return 0;
}