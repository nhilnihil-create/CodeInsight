#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, X;
  cin >> N >> X;
  vector<int> dis(N);
  for (int i = 0; i < N; i++){
    cin >> dis[i];
  }
  
  int sum = 0;
  for (int i = 0; i < N + 1; i++){
    if (i == 0){
      sum += 0;
    }
    else{
      sum += dis[i - 1];
    }
    
    if (sum > X){
      cout << i << endl;
      return 0;
    }
  }
  
  cout << N + 1 << endl;
}
    
