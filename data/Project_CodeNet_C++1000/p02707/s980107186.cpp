#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  int numbers[n];
  for(int i =0; i < n; i++){
      numbers[i] = 0;
  }
  for(int i = 0; i <(n-1); i++){
      int d;
      cin >> d;
      numbers[d-1] += 1;
  }
  for(int i=0; i <n; i++){
      cout << numbers[i] << endl;
  }
}