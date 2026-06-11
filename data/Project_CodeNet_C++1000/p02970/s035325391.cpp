#include <iostream>
using namespace std;
int main(){
  int N, D;
  cin >> N >> D;
  int a = 1 + 2 * D;
  cout << (N + a - 1) / a << endl;
}