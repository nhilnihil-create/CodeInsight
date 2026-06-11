#include <iostream>
#include <string>
using namespace std;
int main(){
  int n;
  string s;
  cin >> n >> s;
  if(n%2==1){
    cout << "No" << "\n";
    return 0;
  }
  else if(s.substr(0,n/2)==s.substr(n/2,n)){
    cout << "Yes" << "\n";
    return 0;
  }
  else cout << "No" << "\n";
  return 0;
}