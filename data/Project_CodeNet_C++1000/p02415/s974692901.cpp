#include <iostream>
#include <string>
#include <cctype>
#define MAXSIZE 101
#define PI 3.141592653589
using namespace std;
int main(){
  string s;
  getline(cin,s);

  for(int i=0;i<s.size();i++){
    if(islower(s[i])){
      s[i]=toupper(s[i]);
    }else if(isupper(s[i])){
      s[i]=tolower(s[i]);
    }
  }
  std::cout << s << '\n';

}