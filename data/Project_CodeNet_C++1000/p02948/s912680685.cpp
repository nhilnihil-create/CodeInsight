#include<bits/stdc++.h>
//#include"atcoder/all"
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
//using namespace atcoder;
int main(){
  int N,M,i;scanf("%d%d",&N,&M);
  pair<int,int> P[N];
  for(i=0;i<N;i++){
    scanf("%d%d",&P[i].second,&P[i].first);
    P[i].second = -P[i].second;
  }
  sort(P,P+N,greater<pair<int,int>>());
  int ans = 0;
  set<int> st;
  for(i=1;i<=M;i++) st.insert(i);
  for(i=0;i<N;i++){
    auto itr = st.lower_bound(-P[i].second);
    if(itr != st.end()){
      ans += P[i].first;
      st.erase(*itr);
    }
    if(st.empty()) break;
  }
  printf("%d\n",ans);
}