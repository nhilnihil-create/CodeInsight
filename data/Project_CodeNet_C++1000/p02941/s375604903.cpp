#include<bits/stdc++.h>

using namespace std;

int main(){
  int N;
  cin >> N;
  
  vector<long long> A(N), B(N);
  for(auto& a : A) cin >> a;
  for(auto& b : B) cin >> b;
  
  priority_queue<pair<long long, int>> pq;
  for(int i = 0; i < N; i++){
    if(A[i] != B[i]) pq.push(make_pair(B[i], i));
  }
  
  long long turn = 0;
  while(!pq.empty()){
    int i = pq.top().second;
    pq.pop();
    
    long long d = B[(N + i - 1) % N] + B[(i + 1) % N];
    
    if(B[i] - A[i] < d){
      turn = -1;
      break;
    }
    
    turn += (B[i] - A[i]) / d;
    B[i] = A[i] + (B[i] - A[i]) % d;
    if(B[i] > A[i]) pq.push(make_pair(B[i], i));
  }
  
  cout << turn << endl;
  
  return 0;
}