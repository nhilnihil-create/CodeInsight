#include<queue>
#include<stack>
#include<math.h>
#include<cmath>
#include<bitset>
#include<stdio.h>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int main(){
  int i,v,e,s,t;
  queue<int> que;
  vector<int> indgree(10010);
  vector<vector<int> > g(10010);
  vector<int> to;
  scanf("%d %d\n",&v,&e);
  for(i=0;i<e;i++){
    scanf("%d %d\n",&s,&t);
    g[s].push_back(t);
    indgree[t]++;
  }
  for(i=0;i<v;i++){
    if(indgree[i]==0){
      que.push(i);
    }
  }
  while(!que.empty()){
    int x=que.front();
    que.pop();
    for(i=0;i<g[x].size();i++){
      int us=g[x][i];
      indgree[us]--;
      if(indgree[us]==0){
        que.push(us);
      }
    }
    to.push_back(x);
  }
  for(i=0;i<to.size();i++){
    printf("%d\n",to[i]);
  }
  return 0;
}
