#include <iostream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <vector>
using namespace std;
int main(){
  int N,M;
  cin>>N>>M;
  priority_queue<int> que;
  for(int i=0;i<N;i++){
    int a;
    cin>>a;
    que.push(a);
  }
  for(int i=0;i<M;i++){
    int n=que.top();
    que.pop();
    que.push(n/2);
  }
  long long answer=0;
  while(!que.empty()){
    answer+=que.top();
    que.pop();
  }
  cout<<answer<<endl;
  
  return 0;
}