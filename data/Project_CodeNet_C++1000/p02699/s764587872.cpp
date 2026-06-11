#include <iostream>
using namespace std;
 
int main(){
    int S,W;
    cin >> S >> W;
  if (S <= W) {
    cout << "unsafe" << endl;
  }
  else if (S > W) {
    cout << "safe" << endl;
  }
}
  