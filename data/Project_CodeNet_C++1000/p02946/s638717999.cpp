#include <iostream>
using namespace std;
int main(){
  int k,x;
  cin >> k >> x;
  int i;
  for(i=x-k+1;i<=x+k-1;i++) cout << i << " ";
  cout << "\n";
  return 0;
}