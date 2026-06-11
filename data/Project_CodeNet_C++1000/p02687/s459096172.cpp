#include<iostream>
#include<string>
using namespace std;
int main(){
  string a, s, g;
  s = "ABC";
  g = "ARC";
  cin >> a;
  if(a == s){
    cout << g << "\n";
    return 0;
  }
  cout << s << "\n";
}