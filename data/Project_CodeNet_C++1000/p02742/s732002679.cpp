#include <iostream>
using namespace std;
using ull = unsigned long long;

ull getResult(const ull height, const ull width){
  if(height <= 1 || width <= 1) return 1;
  return (height * width + 1) / 2;
}

int main(){
  ull H, W;
  cin >> H >> W;
  
  ull result = getResult(H, W);
  cout << result;
  return 0;
}