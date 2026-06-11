#include <iostream>
#include <string>
using namespace std;

int main(){
  string s;
  cin >> s;
  bool ans = true;
  if(s.length() % 2 != 0) ans = false;
  for(size_t i = 0; i < s.length(); i++){
	if(s[i] != ((i%2 == 0) ? 'h' : 'i'))
      ans = false;
  }
  cout << (ans ? "Yes" : "No") << endl;
  return 0;
}