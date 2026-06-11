#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;

vector< vector<int> > G;
ll n, k;
const int mod = 1000000007;
vector<ll> kids;
vector<int> seen;

// rootを決めた場合の、各頂点のkidsの数を数える
// kids[v] := v の 子の数
ll bfs(int v){

    for(int i = 0; i < n; i++){
        seen[i] = 0;
    }

    queue<int> que;
    que.push(v);
    seen[v] = 1;

    ll ans = k;

    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(auto nv : G[now]){
            if(seen[nv] != 0) continue;
            else{
                que.push(nv);
                seen[nv] = 1;
                kids[now]++;
                if(now == v){
                    ans *= (k - 1 - kids[now] + 1);
                    ans %= mod;
                }
                else{
                    ans *= (k - 2 - kids[now] + 1);
                    ans %= mod;
                }
            }
        }
    }

    return ans;
}


int main(void){
    cin >> n >> k;
    G.assign(n, vector<int>());
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    kids.resize(n);
    seen.resize(n);

    cout << bfs(0) << endl;
    return 0;
}