#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
  int N, Q;
  cin >> N >> Q;
  vector<vector<int> > e(N);
  
  for (int i = 0; i < N-1; i++){
    int a, b;
    cin >> a >> b;
    a--, b--;
    e[b].push_back(a);
    e[a].push_back(b);
  }

  queue<int> que;
  que.push(0);
  vector<int> c(N,0);
  vector<int> ans(N,-1);

  for (int i = 0; i < Q; i++){
    int p, x;
    cin >> p >> x;
    c[p-1] += x;
  }

  while(!que.empty()){
    int a=que.front();
    que.pop();
    for(int b:e[a]){
      if(ans[b]!=-1) continue;
      que.push(b);
      c[b]+=c[a]; 
      }
      ans[a]++;
  }

  for (int i = 0; i < N; i++){
    printf("%d ", c[i]);
  }
  printf("\n");
  
}
