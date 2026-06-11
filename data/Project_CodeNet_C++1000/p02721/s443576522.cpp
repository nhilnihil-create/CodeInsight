#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
  long long N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;
  
  int flag[N], flag2[N];
  for (int i = 0; i < N; i++) flag[i] = flag2[i] = -1;
  
  long long now = 0;
  long long count = 0;
  while (count < K){
    if (S[now] == 'o'){
      flag[now] = count;
      now += C;
      count++;
    }
    now++;
  }
  
  now = N - 1;
  count = 0;
  while (count < K){
    if (S[now] == 'o'){
      flag2[now] = K - 1 - count;
      now -= C;
      count++;
    }
    now--;
  }
  
  for (int i = 0; i < N; i++){
    if (flag[i] == flag2[i] && flag[i] >= 0) cout << i + 1 << endl;
  }
}