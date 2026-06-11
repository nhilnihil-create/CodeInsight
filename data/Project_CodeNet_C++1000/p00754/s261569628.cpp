#include<iostream>
#include<string>
#include<stack>
#include<cstdio>

using namespace std;

int main(){
  char match[256];
  string str;

  match['('] = ')';
  match['['] = ']';

  while(getline(cin, str), str != "."){
    stack<char> br;
    bool ans = true;

    for(int i = 0; ans && i < str.size(); i++){
      switch( str[i] ){
      case '(':
      case '[':
        br.push(str[i]);
        break;
      case ')':
      case ']':
        if(br.empty()){
          ans = false;
        }else{
          char c = br.top(); br.pop();
          if(match[c] == str[i]){
          }else{
            ans = false;
          }
        }
        break;
      default:
        break;
      }
    }

    ans = ans && br.empty();

    puts(ans ? "yes" : "no");
  }

  return 0;
}