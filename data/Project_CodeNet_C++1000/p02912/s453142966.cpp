#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M;
  
  cin >> N >> M;
  
  priority_queue<long long> Q;
  
  for (int i = 0; i < N; i++) {
    long long in;
    
    cin >> in;
    
    Q.push(in);
  }
  
  for (int i = 0; i < M; i++) {
    long long tmp = Q.top();
    Q.pop();
    tmp >>= 1;
    Q.push(tmp);
  }
  
  long long sum = 0;
  
  for (int i = 0; i < N; i++) {
    sum += Q.top();
    Q.pop();
  }
  
  cout << sum << endl;
  
  return 0;
}