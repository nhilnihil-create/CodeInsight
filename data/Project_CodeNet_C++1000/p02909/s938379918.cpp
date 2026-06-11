#include<iostream>
#include<string>
using namespace std;
int main(){
  string s;
  cin >> s;
  if(s[0] == 'S'){
    cout << "Cloudy\n";
    return 0;
  }
  if(s[0] == 'C'){
    cout << "Rainy\n";
    return 0;
  }
  cout << "Sunny";
}