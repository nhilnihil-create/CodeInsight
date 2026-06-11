#include <iostream>
#include <cmath>
using namespace std;

int main(){
  int n, k;
  cin >> n >> k;
  int count = 0;
  int x = 1;
  while(1){
    count++;
    if (n < pow(k, x)) break;
    x++;
  }
  cout << count << endl;
  
  return 0;
}