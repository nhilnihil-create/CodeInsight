#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
   int n;
   cin>>n;
   vector<P> e[100000];
   rep(i, n-1){
      int a, b;
      cin>>a>>b; a--; b--;
      e[a].push_back(make_pair(b, i));
      e[b].push_back(make_pair(a, i));
   }

   vector<int> col(n-1, -1);
   queue<int> q;
   q.push(0);
   int mx=0;
   while(!q.empty()){
      int v=q.front(); q.pop();
      int used= -2;
      for(P p : e[v]){
         int u=p.first, ei=p.second;
         if(col[ei]!= -1) used=col[ei];
      }
      int c=0; if(c==used) c++;
      for(P p : e[v]){
         int u=p.first, ei=p.second;
         if(col[ei]!=used){
            col[ei]=c;
            mx=max(mx, c);
            c++; if(c==used) c++;

            q.push(u);
         }
      }
   }

   cout<<(mx+1)<<endl;
   rep(i, n-1) cout<<(col[i]+1)<<endl;
   return 0;
}
