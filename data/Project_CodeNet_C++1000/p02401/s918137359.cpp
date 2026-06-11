#include<iostream>
using namespace std;
int a(int a,int b){return a+b;}
int b(int a,int b){return a-b;}
int c(int a,int b){return a*b;}
int d(int a,int b){return a/b;}
int main(){
  int n,m;
  char op;
  while(cin >> n >> op >> m&& op!='?'){
    if(op=='+')cout << a(n,m) << endl;
    else if(op=='-')cout << b(n,m) << endl;
    else if(op=='*')cout << c(n,m) << endl;
    else if(op=='/')cout << d(n,m) << endl;
  }
}
