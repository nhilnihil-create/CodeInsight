#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include <queue>


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t N, M;
  cin >> N >> M; 

priority_queue<int64_t> A; 

  for (int64_t i = 0; i < N; i++) {
    int64_t tmp; 
    cin >> tmp; 
    A.push(tmp);  
  }


  for (int64_t i = 0; i < M; i++) {
    auto tmp =  A.top(); 
    A.pop(); 
    A.push(tmp/2); 
  }

  int64_t sum = 0;
  for (int64_t i = 0; i < N; i++) {
    sum += A.top(); 
    A.pop(); 
  }
  cout << sum;
  return 0;
}
