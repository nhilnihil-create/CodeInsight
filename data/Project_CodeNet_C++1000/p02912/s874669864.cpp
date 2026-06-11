#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  priority_queue<int> A;
  for (int i = 0; i < N; i++){
    int a;
    cin >> a;
    
    A.push(a);
  }
  
  for (int i = 0; i < M; i++){
    int tar = A.top();
    tar /= 2;
    A.pop();
    A.push(tar);
  }
  
  long long int ans = 0;
  while (!A.empty()){
    ans += A.top();
    A.pop();
  }
  
  cout << ans << endl;
}