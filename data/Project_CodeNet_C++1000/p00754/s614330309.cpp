#include <iostream>
#include <string>
using namespace std;
#define rep(i,n) for(int i = 0 ; i < n ; i++)

int main()
{
  string str;
  int i;
  while(true){
    getline(cin, str);
    if(str[0] == '.') break;
    
    int len = 0;
    while(str[len] != '\0'){
      len++;
    }
        
    int d[101] = {0}, j;
    for(i = 0, j = 0 ; i < len ; i++){
      if(str[i] == '('){
	d[++j] = 1;
      }
      if(str[i] == '['){
	d[++j] = 2;
      }
      if(str[i] == ')'){
	if(d[j--]-1){
	  break;
	}
      }
      if(str[i] == ']'){
	if(d[j--]-2){
	  break;
	}
      }
    }
    if(str[i] || j){
      cout << "no" << '\n';
    }else{
      cout << "yes" << '\n';
    }
  }
}