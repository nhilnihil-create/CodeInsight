#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int main(){
  int N;
  cin>>N;
  vector<int> path[100000];
  int ver[100000][2];
  vector<int> aro[100001];
  for(int i=1;i<N;i++){
    int a,b;
    cin>>a>>b;
    ver[i][0]=a;
    ver[i][1]=b;
    aro[a].push_back(i);
    aro[b].push_back(i);
  }
  int num=0;
  for(int i=1;i<=N;i++) if(num<aro[i].size()) num=aro[i].size();
  cout<<num<<endl;
  int color[100000];
  int search[100001];
  for(int i=1;i<=N;i++) search[i]=0;
  queue<int> que;
  que.push(1);
  color[1]=1;
  while(!que.empty()){
    int n=que.front();
    que.pop();
    int a=ver[n][0];
    int b=ver[n][1];
    int j=1;
    int k=1;
    if(search[a]==0){
      search[a]++;
    for(int i=0;i<aro[a].size();i++){
      if(j==color[n]) j++;
      if(aro[a][i]!=n){
        color[aro[a][i]]=j;
        que.push(aro[a][i]);
        j++;
      }
    }
    }
    if(search[b]==0){
      search[b]++;
    for(int i=0;i<aro[b].size();i++){
      if(k==color[n]) k++;
      if(aro[b][i]!=n){
        color[aro[b][i]]=k;
        que.push(aro[b][i]);
        k++;
      }
    }
    }
  }
  for(int i=1;i<N;i++) cout<<color[i]<<endl;
  
  return 0;
}