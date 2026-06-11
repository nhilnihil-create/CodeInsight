#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  int left = 0;
  int right = 1e9;
  while(right-left>1){
    int x = (left+right)/2;
    int num = 0;
    for(int i=0; i<N; i++){
      num += A.at(i)/x - (A.at(i)%x==0);
    }
    if(num<=K){
      right = x;
    }else{
      left = x;
    }
  }
  cout << right;
  return 0;
}
