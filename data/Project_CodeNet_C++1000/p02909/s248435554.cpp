#include <iostream>
#include <string>
using namespace std;
int main(){
  string s;
  int i,n;
  cin >> s;
  if(s=="Sunny") s="Cloudy";
  else if(s=="Cloudy") s="Rainy";
  else s="Sunny";
  cout << s << endl;
  return 0;
}