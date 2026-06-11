#include<iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  priority_queue<unsigned long long, vector<unsigned long long>, less<unsigned long long> > A;
  for(int i = 0; i < N; i++){
    unsigned long long tmp;
    cin >> tmp;
    A.push(tmp);
  }

  for(int i = 0; i < M; i++){
    unsigned long long x = A.top();
    A.pop();
    x /= 2;
    A.push(x);
  }
  
  unsigned long long ans = 0;
  for(int i = 0; i < N; i++){
    ans += A.top();
    A.pop();
  }

  printf("%llu\n", ans);
  
  
}
