#include <iostream>
 
using namespace std;
 
int main()
{
  int A, B ,C;
  cin >> A >> B >> C;
  
  if (A == B && B != C) {
  	cout << "Yes\n";
  }
  else if (B == C && C != A) {
  	cout << "Yes\n";  
  }
  else if (C == A && A != B) {
  	cout << "Yes\n";  
  }
  else {
    cout << "No\n";
  }
}