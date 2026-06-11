#include <iostream>

using namespace std;

int main(){
  string a;
  cin >> a;
  if(a.at(0)==a.at(1)&&a.at(1)==a.at(2)) cout << "No";
  else if(a.at(0)==a.at(1)&&a.at(2)==a.at(3)) cout << "Yes";
  else if(a.at(0)==a.at(2)&&a.at(1)==a.at(3)) cout << "Yes";
  else if(a.at(0)==a.at(3)&&a.at(1)==a.at(2)) cout << "Yes";
  else cout << "No";
}
