#include<bits/stdc++.h>

using namespace std;

int main(void){
  int N;
  cin >> N;
  if(N & (N - 1)){
    cout << "Yes" << "\n";
  }else{
    cout << "No" << "\n";
    return 0;
  }
  cout << 1 << " " << 2 << "\n";
  cout << 2 << " " << 3 << "\n";
  cout << 3 << " " << N + 1 << "\n";
  cout << N + 1 << " " << N + 2 << "\n";
  cout << N + 2 << " " << N + 3 << "\n";
  for(int i = 4; i < N; i += 2){
    cout << i << " " << i + 1 << "\n";
    cout << i + 1 << " " << N + 1 << "\n";
    cout << i + N << " " << N + 1 << "\n";
    cout << i + 1 + N << " " << i + N << "\n";
  }
  if(N % 2 == 0){
    int b = 1;
    int NN = N;
    while(NN > 1){
        NN >>= 1;
        b <<= 1;
    }
    cout << N << " " << b + N << "\n";
    cout << 2 * N << " " << (b ^ N ^ 1) << endl;
  }
  return 0;
}
