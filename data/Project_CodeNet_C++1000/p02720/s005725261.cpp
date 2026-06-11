#include <iostream>
#include <queue>

using namespace std;

int main(){
  int K;
  cin >> K;
  queue<long long> q;

  for (int i = 1; i < 10; i++){
    q.push(i);
  }

  long long x;
  for (int i = 0; i < K; i++){
    x = q.front();
    q.pop();
    if(x%10 != 0){
      q.push(10*x + x%10 - 1);
    }
    q.push(10*x + x%10);

    if(x%10 != 9){
      q.push(10*x + x%10 + 1);
    }
  }
  
  printf("%lld\n", x);
  
}
