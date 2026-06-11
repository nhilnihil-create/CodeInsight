#include<bits/stdc++.h>

using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> a((N - 1) >> 1), b((N - 1) >> 1);
  
  for(int i = 1; i <= (N - 1) >> 1; i++){
    a[i - 1] = i;
    b[((N - 1) >> 1) - i] = ((N - 1) >> 1) + i;
  }
  
  if((N ^ 1) & 1){
    for(int i = 0; i < ((N - 1) >> 2); i++){
      ++b[i];
    }
  }
  
  for(int i = 0; i < M; i++){
    cout << a[i] << ' ' << b[i] << endl;
  }
  
  return 0;
}