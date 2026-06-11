#include<iostream>

using namespace std;

int main(){
  int a, b;
  cin >> a >> b;
  
  int diff = abs(b - a);
  
  if(diff % 2 == 0){
    if (a > b)
      cout << abs(a - (diff / 2)) << endl;
    else
      cout << abs(b - (diff / 2)) << endl;
  }
  else{
    cout << "IMPOSSIBLE" << endl;
  }
}