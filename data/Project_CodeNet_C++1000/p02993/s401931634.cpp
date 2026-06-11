#include <iostream>

using namespace std;

int main(){
  string a;
  cin >> a;
  int b = 0;
  for(int i = 0;i<3;i++){
    if(a.at(i)==a.at(i+1)) b = 1;
  }
  if(b)cout << "Bad";
  else cout << "Good";
}
