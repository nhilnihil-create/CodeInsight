/*
  The Balance of the World
  http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1173&lang=jp
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main(void){
  while(1){
    string s;
    vector<char> v;
    getline(cin, s);
    if(s[0] == '.') break;

    int ptr = 0;
    bool correct = true;
    while(correct && ptr < s.length()){
      switch( s[ptr] ){
        case '(' :
          v.push_back('(');
          ptr++;
          break;
        case '[' :
          v.push_back('[');
          ptr++;
          break;
        case ')' :
          if( !v.empty() && v.back() == '('){
            v.pop_back();
            ptr++;
          }else{
            correct = false;
          }
          break;
        case ']' :
          if( !v.empty() && v.back() == '['){
            v.pop_back();
            ptr++;
          }else{
            correct = false;
          }
          break;
        default:
          ptr++;
          break;
      }
    }

    if(v.empty() && correct){
      cout << "yes" << endl;
    }else{
      cout << "no"  << endl;
    }
  }

  return 0;
}