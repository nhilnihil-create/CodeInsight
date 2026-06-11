#include <iostream>
using namespace std;
 
int main(){
    int N;
    cin >> N;
  
  int a = N/100;
  int b = (N-100*a)/10;
  int c = N-(100*a+10*b);
    
    if (a == 7 || b == 7 || c == 7) {
      cout << "Yes" << endl;
    }
  else {
    cout << "No" << endl;
  }
}