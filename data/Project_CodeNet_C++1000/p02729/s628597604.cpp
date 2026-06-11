#include <iostream>
using namespace std;
int C(int n){
  return n*(n-1)/2;
}

int main(){
  int a,b;
  cin >> a >> b;
  cout << C(a)+C(b) << endl;
}
  