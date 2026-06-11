#include <iostream>
#include <array>
using namespace std;

int main(){
  array<int, 32> arr = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
  int a;
  cin >> a;
  cout << arr.at(a-1) << '\n';
  
  return 0;
}