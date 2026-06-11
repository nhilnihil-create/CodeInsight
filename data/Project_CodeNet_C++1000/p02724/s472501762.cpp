#include <iostream>
#include <string>
using namespace std;
int main(){
  int N;  
  cin >> N;  
  int n = N/500;  
  int m = (N-n*500)/5;  
  cout << 1000*n+5*m << endl;  
  return 0;
}