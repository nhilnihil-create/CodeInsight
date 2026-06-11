#include <iostream>
#include <vector>
using namespace std; 
int main(void){

  int n;
  cin >> n;
  
  vector<int> vec(n);
  for (int i = 0; i < n; i++) {
    cin >> vec.at(i);
  }
  
  int result = 0;
  
  for(int i = 0; i < n; i++){
    for(int j = i; j < n; j++){
      if (i == j){
        continue;
      }
      result += vec.at(i) * vec.at(j);
    }
  }
   
  cout << result << endl;
  return 0;
}
