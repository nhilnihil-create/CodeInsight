#include<iostream>
#include<string>
#define N 200
using namespace std;
int h,t,stack[N];

int stoi(string s){
  int r=0;
  for(int i=0;i<s.size();i++)r=r*10+s[i]-'0';
  return r;
}

void push(int x){
  stack[t]=x;
  t++;
}

int front(){
  return stack[t-1];
}

void pop(){
  t--;
}

int main(){
  string s;
  int a,b;
  h=0,t=1;
  while(cin>>s){
    if('0'<=s[0]&&s[0]<='9'){
      push(stoi(s));
    }
    else{
      a=front(); pop();
      b=front(); pop();
    }
    if(s=="+")push(b+a);
    if(s=="-")push(b-a);
    if(s=="*")push(b*a);
  }
  cout<<front()<<endl;
  return 0;
}