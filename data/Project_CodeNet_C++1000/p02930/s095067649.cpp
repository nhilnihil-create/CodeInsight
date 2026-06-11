#include<iostream>
using namespace std;

int main(){
  int N;
  cin >> N;

  int highest_bit_N = 0;
  for(; (1 << highest_bit_N) <= N - 1; highest_bit_N++){
  }
  // N = 4 -> 2
  // N = 5 -> 3
  // cout << highest_bit_N << endl;

  for(int i = 0; i < N - 1; i++){
    for(int j = i + 1; j < N; j++){
      if(j != i + 1){
        cout << ' ';
      }
      int highest_diff_bit = 10;
      while((i & (1 << highest_diff_bit)) == (j & (1 << highest_diff_bit))){
        highest_diff_bit--;
      }
      cout << highest_diff_bit + 1;
    }
    cout << endl;
  }
}
