#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

using namespace std;

string data[10] = {"", ".,!? ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

main(){
  int n;
  cin >> n;
  getchar();
  while(n--){
    char in;
    string out;
    char pre = '0';
    char c = 0;
    int p = 0;
    while(1){
      scanf("%c", &in);
      if(in == '\n') break;
      if(in == '0'){
        if(c != 0) out += c;
        c = 0;
      }else{
        if(pre != in) p = 0;
        else p = (p+1)%((int)data[in-'0'].size());
        c = data[in-'0'][p];
      }
      pre = in;
    }
    cout << out << endl;
  }
  return 0;
}