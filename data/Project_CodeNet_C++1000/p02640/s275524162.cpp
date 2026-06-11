using namespace std;
#include <iostream>
#include <string>

int main(){
  int X, Y;
  cin >> X >> Y;
  
  int sum;
  
  for (int i = 0; i <= X; i++){
    sum = 2 * i + 4 * (X - i);
    if (sum == Y){
      cout << "Yes";
      return 0;
    }
  }
  
  cout << "No";
  return 0;
}