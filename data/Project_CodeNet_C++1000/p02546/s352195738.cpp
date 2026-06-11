#include <iostream>
#include <string>

using namespace std;

int main(){
  string s;
  cin >> s;
  int l = s.size();
  string slast = s.substr(l-1);

  if(slast == "s"){
    cout << s.insert(l, "es");
  }
  else{
    cout << s.insert(l, "s");
  }

  return 0;
}