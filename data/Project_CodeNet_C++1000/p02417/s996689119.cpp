#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
  string line;
  map<char, int> m;
  const char tmp = 'a';
  for(int i=0; i<26; i++) {
    m[tmp+i] = 0;
  }
  
  
  while(cin >> line) {
    for(unsigned int i = 0; i<line.length(); i++) {
      if('a' <= line[i] && line[i] <= 'z') {
        m[line[i]] += 1;
      }
      else if('A' <= line[i] && line[i] <= 'Z') {
        m[line[i]+32] += 1;
      }
    }
  }
  for(int i=0; i<26; i++) {
    cout << (char)(tmp+i) << " : " << m[tmp+i] << endl;
  }

  return 0;
}