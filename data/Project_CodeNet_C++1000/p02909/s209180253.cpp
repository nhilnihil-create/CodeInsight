#include <iostream>
#include <string>
using namespace std;
int main(){
  string S[4] ={"Sunny","Cloudy","Rainy","Sunny"};
  string t;
  cin >> t;
  for(int i = 0; i < 3; i++){
    if(S[i] == t) {
      cout << S[i+1] << endl;
      return 0;
    }
  }
}
