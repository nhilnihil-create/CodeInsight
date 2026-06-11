#include<bits/stdc++.h>
#define Bye return 0
#define ll long long

using namespace std;

void solve(){
   int n, m; cin>>n>>m;

   vector<int> h(n), cont_got(n), cont_total(n);
   for (int i=0; i<n; i++) cin>>h[i];

   for (int i=0; i<m; i++){
       int u, v; cin>>u>>v; u--; v--;

       cont_got[u] += (h[u]>h[v]);
       cont_got[v] += (h[v]>h[u]);

       cont_total[u]++;
       cont_total[v]++;
   } 

   int res = 0;
   for (int i=0; i<n; i++)
        res += (cont_total[i] == cont_got[i]);

    cout<<res<<endl;
}

int main(){
    solve();
    Bye;
}