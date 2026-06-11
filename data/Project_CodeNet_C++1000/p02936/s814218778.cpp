#include <bits/stdc++.h>
using namespace std;

int P[300000];
vector<vector<int>> G;
vector<bool> seen;
void dfs(int a) {
    seen[a]=true;
    for (auto b : G[a]) {
        if (seen[b]) continue;
        P[b]+=P[a];
        dfs(b);
    }
}
int main() {
   int N,Q;
   cin >> N >> Q;
    G.resize(N+1);
   for (int i=0; i<N-1; i++) {
       int a,b;
       cin >> a >> b;
       G[a].push_back(b);
       G[b].push_back(a);
   }
   for (int i=0; i<N; i++) {
       P[i+1]=0;
   }
   for (int i=0; i<Q; i++) {
       int p,x;
       cin >> p >> x;
       P[p]+=x;
   }
   seen.assign(N+1,false);
   dfs(1);
   for (int i=0; i<N; i++) {
       cout << P[i+1] ;
       if (i==N-1) cout << endl;
       else cout << " " ;
   }
}