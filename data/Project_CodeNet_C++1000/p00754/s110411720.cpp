#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
  int i, isCorrect;
  string str, _str;

  while(1){
    getline(cin, str);
    if(str == ".") break;

    for(i=0, isCorrect=1; i<str.size(); ++i){
      if(str[i] == '(' || str[i] == '['){
	_str.push_back(str[i]);
      }else if(str[i] == ')'){
	if(_str.size() == 0 || _str[_str.size()-1] != '(')
	  isCorrect = 0;
	else
	  _str.erase(_str.end()-1);
      }else if(str[i] == ']'){
	if(_str.size() == 0 || _str[_str.size()-1] != '[')
	  isCorrect = 0;
	else
	  _str.erase(_str.end()-1);
      }

      if(isCorrect == 0) break;
    }

    if(isCorrect == 1 && _str.size() == 0)
      cout << "yes" << endl;
    else
      cout << "no" << endl;

    str.clear();
    _str.clear();
  }

  return 0;
}