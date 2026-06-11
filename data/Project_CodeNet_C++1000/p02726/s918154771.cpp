#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i=0; i<n; ++i)
#define repit(it, li) for(auto it=li.begin(); it!=li.end(); it++)
#define ll long long int

int main(){
   int n, x, y;
   cin>>n>>x>>y;
   x--; y--;

   vector<int> e[2000];
   rep(i, n-1){
      e[i].push_back(i+1);
      e[i+1].push_back(i);
   }
   e[x].push_back(y);
   e[y].push_back(x);

   vector<int> c(n);
   rep(i, n){
      vector<bool> mita(n);
      queue<int> q, nq;
      q.push(i);
      mita[i]=true;
      int k=1;
      while(!q.empty()){
         while(!q.empty()){
            int v=q.front(); q.pop();
            repit(it, e[v]) if(!mita[*it]){
               c[k]++;
               nq.push(*it);
               mita[*it]=true;
            }
         }
         swap(q, nq);
         k++;
      }
   }

   for(int i=1; i<=n-1; i++) cout<<(c[i]/2)<<endl;
   return 0;
}
