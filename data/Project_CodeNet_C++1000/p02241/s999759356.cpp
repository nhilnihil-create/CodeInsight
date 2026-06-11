#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

template<class E>
using nega_queue=priority_queue<E,vector<E>,greater<E>>;

UL N;
UL UF[100];
void unite(UL a,UL b){
 a=UF[a]; b=UF[b];
 rep(i,N) if(UF[i]==b) UF[i]=a;
}

int main() {
 scanf("%u",&N);
 nega_queue<pair<int,pair<UL,UL>>> G;
 rep(i,N) rep(j,N){
  int d; scanf("%d",&d);
  if(d!=-1) G.push({d,{i,j}});
 }
 int ans=0;
 rep(i,N) UF[i]=i;
 while(G.size()){
  int d=G.top().first;
  UL u=G.top().second.first;
  UL v=G.top().second.second;
  G.pop();
  if(UF[u]==UF[v]) continue;
  unite(u,v);
  ans+=d;
 }
 printf("%d\n",ans);
 return 0;
}

