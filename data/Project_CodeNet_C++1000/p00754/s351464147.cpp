#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string setup(string s){
  string ns = "";
  for(int i=0; i<s.length(); i++){
    if(s[i] == '(' || s[i] == ')' || s[i] == '[' || s[i] == ']'){
      ns += s[i];
    }
  }
  return ns;
}

int main(void){
  
  while(1){
    string line;
    getline(cin,line);
    
    if(line == ".") break;
    
    // remove other chars
    line = setup(line);
    int a, b;
    
    while((a=line.find("()")) != -1 || (b=line.find("[]")) != -1){
      if(a != -1){
        line.erase(a, 2);
      } else if(b != -1){
        line.erase(b, 2);
      }
    }
    
    if(line.length() != 0){
      cout << "no" << endl;
    } else {
      cout << "yes" << endl;
    }
    
  }
  
  return 0;
}