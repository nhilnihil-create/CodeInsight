#include <bits/stdc++.h>
using namespace std;

int main(){
  double A, B, X;
  const double PI = 3.1415926535897;
  cout << fixed << setprecision(10);
  
  cin >> A >> B >> X;
  
  if (B < 2 * X / (A * A)){
    
  	cout << atan((B - X / (A * A)) * 2 / A) * 180 / PI << endl;
    
  }
  else{
    
    cout << atan(A * B * B / (2 * X)) * 180 / PI << endl;
    
  }
}