#include<iostream>
#include<string.h>
using namespace std;

int main(){
  int a,b;
  char c;

  while(1){
    cin >> a >> c >> b;
    if(strcmp(&c,"?")==0) break;
    if(strcmp(&c,"+")==0) cout << a+b << endl;
    if(strcmp(&c,"-")==0) cout << a-b << endl;
    if(strcmp(&c,"*")==0) cout << a*b << endl;
    if(strcmp(&c,"/")==0) cout << a/b << endl;
  }

  return 0;
}