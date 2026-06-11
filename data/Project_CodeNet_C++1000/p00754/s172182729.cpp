#include<iostream>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;

int main(){

  string str,z,x;

  while(1){

    stack < string > a;
    int count = -1,d;
    z = "0";
    a.push("0");
    d = a.size();
    getline(cin,str);

    if(str == ".") break;

    for(int i=0;i<str.size();i++){

      if((a.size() == d && str[i] == ')') || (a.size() == d && str[i] == ']')){
	count = 0;
        break;
      }
      if(str[i] == '('){
	x = str[i];
	a.push(x);
	z = a.top();
      }
      else if(str[i] == '['){
	x = str[i];
	a.push(x);
	z = a.top();
      }
      else if(z == "(" && str[i] == ')'){
	a.pop();
	z = a.top();
      }
      else if(z == "[" && str[i] == ']'){
	a.pop();
	z = a.top();
      }
      else if(z == "(" && str[i] == ']'){
	count = 0;
	break;
      }
      else if(z == "[" && str[i] == ')'){
	count = 0;
	break;
      }
    }
    
    if(count == 0 || a.size() != d) cout << "no" << endl;
    else cout << "yes" << endl;
  }
}