#include <iostream>
#include <vector>
using namespace std;

int main(){
  int N;
  cin >> N;
  int x = N%1000;
  if(x){
    cout << 1000 - x;
  }else{
    cout << 0;
  }
  return 0;
}