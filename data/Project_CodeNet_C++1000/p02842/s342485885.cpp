#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  double X;
  X = N * 100 / 108;
  for(int i = X-2; i<= X+1 ; i++){
    if(i * 108 /100 == N){
      cout << i << endl;
      return 0;
    }
  }
  cout << ":(" <<endl;
}