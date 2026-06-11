#pragma GCC optimize("Ofast")
#include  "bits/stdc++.h"
using namespace std;
#define I_AM_SPEED  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
#define printclock  cerr <<"Time : "<<(double)clock()/(double)CLOCKS_PER_SEC<<" sec\n";
#define mp(a , b)   make_pair(a , b)
#define eb(a)       emplace_back(a)
#define SZ(n)       ((int)(n).size())
#define all(n)      (n).begin(), (n).end()
#define anal           '\n'
#define mod         1000000007
#define fst         first
#define sec         second
#define pr(n)       cerr << n  << " ";
#define pfor(a)     for(auto (w) : (a)) pr(w)
//const double PI = acos(-1.0);
typedef long long ll;
typedef unsigned long long ull;

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

bool vis[300010];
int C = 0;
void DFS(vector<int> G[], int v){
      vis[v] = 1;
      for(int u : G[v]){
          if(!vis[u]){
              C++;
              DFS(G, u);
          }
      }
}

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
int main(){
I_AM_SPEED;
#ifndef ONLINE_JUDGE  
        freopen("input.in", "r", stdin);
        freopen("output.in", "w", stdout);
#endif 
//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
    
   int n, m;
   cin >> n >> m;
   vector<int> G[n + 1];
   for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        G[x].eb(y);
        G[y].eb(x);
   }
   int ans = 0;
   for(int i = 1; i <= n; i++){
         if(!vis[i]){
             C = 1;
             DFS(G, i);
             ans = max(ans, C);
         }
   }
   cout << ans << anal;

//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-
//printclock; 
return  0 ;      
}        



      