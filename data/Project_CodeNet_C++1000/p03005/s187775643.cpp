#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
  int N;
  int K;
  cin >> N >> K;
  if(K!=1){
    cout << N-K << endl;
  }
  else{
    cout << 0 << endl;
  }


  return 0;
}