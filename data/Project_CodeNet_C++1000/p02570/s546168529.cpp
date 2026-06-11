#include <iostream>

using namespace std;

int main() {

  int d, t, v;
  cin >> d >> t >> v;
  if(t * v >= d){
     cout << "Yes";
  }else{
    cout << "No";
  }
  return 0;
}
