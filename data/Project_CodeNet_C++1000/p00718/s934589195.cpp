#include<iostream>
#include<string>
using namespace std;
int summ(string,string);
int NtoM(string);
void MtoN(int);
int main(){
  int n,ans;
  string a,b;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> a >> b;
    ans=summ(a,b);
    MtoN(ans);
  }
  return 0;
}
int summ(string a,string b){
  return  NtoM(a)+NtoM(b);
}
int NtoM(string a){
  int st=1;
  int x=0;
  for(int i=0;i<a.size();i++){
    if(a[i]>='0'&&a[i]<='9'){
      st=a[i]-'0';
    }
    else{
      if(a[i]=='m'){
	x+=st*1000;
      }
      else if(a[i]=='c'){
	x+=st*100;
      }
      else if(a[i]=='x'){
	x+=st*10;
      }
      else if(a[i]=='i'){
	x+=st;
      }
      st=1;
    }
  }
  return x;
}
void MtoN(int a){
  string x;
  x.clear();
  if(a/1000!=0){
    if(a/1000!=1)
      x+='0'+a/1000;
    x+='m';
    a%=1000;
  }
  if(a/100!=0){
    if(a/100!=1)
      x+='0'+a/100;
    x+='c';
    a%=100;
  }  
  if(a/10!=0){
    if(a/10!=1)
      x+='0'+a/10;
    x+='x';
    a%=10;
  }
  if(a!=0){
    if(a!=1)
      x+='0'+a;
    x+='i';
  }
  cout << x << endl;
}