#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  vector<int> fri[200001];
  for(int i=0;i<M;i++){
    int A,B;
    cin>>A>>B;
    fri[A].push_back(B);
    fri[B].push_back(A);
  }
  int answer=0;
  int search[200001];
  for(int i=1;i<=N;i++) search[i]=0;
  for(int i=1;i<=N;i++){
    if(search[i]==0){
      search[i]=1;
      queue<int> que;
      que.push(i);
      int judge=0;
      while(!que.empty()){
        int x=que.front();
        que.pop();
        for(int j=0;j<fri[x].size();j++){
          if(search[fri[x][j]]==0){
            que.push(fri[x][j]);
            search[fri[x][j]]=1;
          }
        }
        judge++;
      }
      answer=max(answer,judge);
    }
  }
  cout<<answer<<endl;
  
  return 0;
}