#include <iostream>
using namespace std;

int main() {
string S="Rainy";
cin >> S;
if(S=="Sunny"){
  cout << "Cloudy";
}else if(S=="Cloudy"){
  cout << "Rainy";
}else if(S=="Rainy"){
  cout << "Sunny";
}
	return 0;
}

