#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

vector<UL> E[100000];
UL D[100000];

int main() {
 UL N,M; scanf("%u%u",&N,&M);
 rep(i,M){
  UL u,v; scanf("%u%u",&u,&v);
  E[u].push_back(v);
  E[v].push_back(u);
 }
 rep(i,N) D[i]=~0u;
 rep(s,N){
  if(D[s]!=~0u) continue;
  queue<UL> Q; Q.push(s); D[s]=s;
  while(Q.size()){
   UL p=Q.front(); Q.pop();
   for(UL e:E[p]){
    if(D[e]!=~0u) continue;
    D[e]=D[p];
    Q.push(e);
   }
  }
 }
 UL Q; scanf("%u",&Q);
 rep(q,Q){
  UL s,t; scanf("%u%u",&s,&t);
  if(D[s]==D[t]) printf("yes\n");
  else printf("no\n");
 }
 return 0;
}

