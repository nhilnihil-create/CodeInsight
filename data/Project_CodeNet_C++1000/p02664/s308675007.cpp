#include<iostream>
#include<string>

using namespace std;

int main(){
  string s;
  std::cin >> s;
  int ans = 0;
  for (int i = 0; i < s.length(); i++) {
    if(s[i] == '?')s[i] = 'D';
  }
  std::cout << s << std::endl;
  return 0;
}
