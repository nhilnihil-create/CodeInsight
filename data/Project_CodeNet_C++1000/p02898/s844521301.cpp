#include <iostream>
#include <vector>
using namespace std; 
int main(void){

  int n, k;
  cin >> n >> k;
  
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  
  int result = 0;
  
  for(int h : vec){
    if (k <= h){
      result++;
    }
  }
   
  cout << result << endl;
  return 0;
}