#include<bits/stdc++.h>
#define ll long long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
static const ll MAX = 1000000000000000;
static const int NIL = -1;
using namespace std;
const long double EPS = 0.0000000001;
const long double PI = (acos(-1));
const int MOD = 1000000007;

#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")


int main(){
    int n,q;
    cin >> n >> q;
    vector<int> value(n+1);
    vector<vector<int>> G(n+1);
    rep(i,n-1){
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    rep(i,q){
        int a,b;
        cin >> a >> b;
        value[a] += b;
    }

    queue<int> q1;
    q1.push(1);
    vector<bool> visited(n+1,false);

    while(!q1.empty()){
        int nq = q1.front();
        q1.pop();
        visited[nq] = true;


        rep(i,G[nq].size()){
            if(visited[G[nq][i]] == true) continue;
            value[G[nq][i]] += value[nq];
            q1.push(G[nq][i]);
        }
    }

    for(int i = 1;i <= n;i++) cout << value[i] << " ";
    cout << endl;

}