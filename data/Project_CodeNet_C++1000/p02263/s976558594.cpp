#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Stack{
private:
  int size;
  int array[200];
public:
  Stack(){
    size = 0;
  }
  bool isEmpty();
  void push(int num);
  int pop();
};

bool Stack::isEmpty(){
  if(size == 0) return true;
  else return false;
}

void Stack::push(int num){
  array[size++] = num;
}

int Stack::pop(){
  return array[--size];
}

int main(void){ 
  Stack st;
  char s[100];
  while(scanf("%s", s) != EOF){
    if(s[0] == '+'){
      int a = st.pop();
      int b = st.pop();
      st.push(a + b);
    }else if(s[0] == '-'){
      int a = st.pop();
      int b = st.pop();
      st.push(b - a);
    }else if(s[0] == '*'){
      int a = st.pop();
      int b = st.pop();
      st.push(a * b);
    }else{
      st.push(atoi(s));
    }
  }
  cout << st.pop() << endl;
  return 0;
}