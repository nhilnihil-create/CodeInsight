#include <iostream>
#include <string>
struct stuck{
  int s[100];/*量に応じて変更*/
  int top;
  void initialize(){
    top=0;
  }
  bool isEmpty(){
    return top==0;
  }
  void push(int x){
    s[top]=x;
    top++;
  }
  int pop(){
    if (isEmpty()){
      std::cout << "Empty" << '\n';
      return -1;
    }else{
      top--;
      return s[top];
    }
  }
};

int main(){
  int a,b;
  struct stuck d;
  d.initialize();
  std::string s;
  while (std::cin >> s){
    if (s=="+"){
      a=d.pop();b=d.pop();
      d.push(b+a);
    }else if (s=="-"){
      a=d.pop();b=d.pop();
      d.push(b-a);
    }else if (s=="*"){
      a=d.pop();b=d.pop();
      d.push(b*a);
    }else {
      a=atoi(s.c_str());
      d.push(a);
    }
  }
  if (d.isEmpty()){
    std::cout << "Error" << '\n';
  }else{
    std::cout << d.pop() << '\n';
  }
}

