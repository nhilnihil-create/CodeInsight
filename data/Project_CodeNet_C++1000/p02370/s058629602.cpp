#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <climits>
#include <utility>
typedef long long ll;
using namespace std;

int v,e;
int cnt[10000]={};
bool visited[10000]={};
vector<int> edge[10000];

void print(int v){
  int i;
  if(visited[v])return;

  printf("%d\n",v);
  visited[v]=1;
  for(i=0;i<edge[v].size();i++){
    cnt[edge[v][i]]--;
    if(cnt[edge[v][i]]==0){
      print(edge[v][i]);
    }
  }
}

int main(void){
  int s,t,i,j;
  cin>>v>>e;
  for(i=0;i<v;i++){
    edge[i].clear();
  }

  for(i=0;i<e;i++){
    cin>>s>>t;
    edge[s].push_back(t);
    cnt[t]++;
  }

  for(i=0;i<v;i++){
    if(cnt[i]==0)print(i);
  }

  return 0;
}
