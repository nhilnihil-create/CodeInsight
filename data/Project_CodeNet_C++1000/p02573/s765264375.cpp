#include<bits/stdc++.h>
using namespace std;

int main(){
  
  int N, M;
  cin >> N >> M;
  vector<set<int>> V(N+1);
  
  for(int i = 0; i<M; i++){
    int A, B;
    cin >> A >> B;
    V[A].insert(B);
    V[B].insert(A);
  }
  
  
  vector<bool> visited(N+1, false);
  queue<int> que;
  
  int ans = 0;
  
  for(int i = 1; i<N+1; i++){
    if(!visited[i]){
      
      int sum = 1;
      
      visited[i] = true;
      que.push(i);
      
      while(!que.empty()){
        int v = que.front();
        que.pop();
        
        for(int nv : V[v]){
          if(visited[nv]) continue;
          
          sum++;
          visited[nv] = true;
          que.push(nv);
        }
      }
      
      ans = max(ans, sum);
    }
  }
  
  cout << ans << endl;       
}



