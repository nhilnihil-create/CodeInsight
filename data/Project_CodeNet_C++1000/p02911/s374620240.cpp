#include <iostream>
#include <algorithm>

using namespace std;

int main(){
  int N, Q;
  long long K;
  cin >> N >> K >> Q;
  long long A[N];
  for (int i = 0; i < N; i++){
    A[i] = 0;
  }

  for (int i = 0; i < Q; i++){
    int q;
    cin >> q;
    A[q-1]++;
  }


  for (int i = 0; i < N; i++){
    A[i] = K - ((long long)Q - A[i]);
  }
  
  for (int i = 0; i < N; i++){
    if (A[i] > 0){
      printf("Yes\n");
    }else{
      printf("No\n");
    }
  }
  

}
