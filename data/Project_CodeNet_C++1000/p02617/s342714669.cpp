#include<bits/stdc++.h>
using namespace std;
using UL = unsigned int;
using ULL = unsigned long long;
using LL = long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

UL N;
vector<UL> E[200000];
UL P[200000];
ULL ans=0;

int main() {
 scanf("%u",&N);
 rep(i,N-1){
  UL u,v; scanf("%u%u",&u,&v); u--; v--;
  E[u].push_back(v);
  E[v].push_back(u);
 }
 rep(i,N) P[i]=~0u;
 queue<UL> Q; Q.push(0);
 while(Q.size()){
  UL p=Q.front(); Q.pop();
  for(UL e:E[p]){
   if(P[p]==e) continue;
   P[e]=p; Q.push(e);
  }
 }

 ans+=N;
 for(UL i=1; i<N; i++){
  UL a=i, b=P[i];
  ULL tmp;
  if(a<b) tmp = ULL(a+1) * (b-a);
  else tmp = ULL(N-a) * (a-b);
  ans+=tmp;
 }

 printf("%llu\n",ans);

 return 0;
}

