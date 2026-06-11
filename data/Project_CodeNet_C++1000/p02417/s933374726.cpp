#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char s;
int cnt[26];

int main(){

  while(cin >> s){
    s = tolower(s);
    if(s >= 'a' && s <= 'z')
      cnt[(int)(s - 'a')]++;
  }

  for (int i = 0; i < 26; i++) {
    cout << (char)(i + 'a') << " : " << cnt[i] << endl;
  }
}