#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int64_t n,c,d,e;
 cin>>n;
 c=0;//0のかず
 d=1000;
 e=0;
 vector<int>a(n);
 vector<int>b(n-1);
 for(int i=0;i<n;i++){
   cin>>a.at(i);
 }
 for(int i=1;i<n;i++){
   if(a.at(i)<a.at(i-1)){
     b.at(i-1)=-1;
    }
    else if(a.at(i)>a.at(i-1)){
      b.at(i-1)=1;
    }
    else{
      b.at(i-1)=0;
      c++;
    }
  }
  vector<int>x(n-c);
  x.at(0)=a.at(0);
  int j=1;
  for(int i=0;i<n-1;i++){
    if(b.at(i)==0){
      continue;
    }
    else{
      x.at(j)=a.at(i+1);
      j++;
    }
  }
  if(n-c!=1){
  if(x.at(1)>x.at(0)){
    e=d/x.at(0);
    d=d%x.at(0);
  }
  }
  for(int i=1;i<n-c-1;i++){
    if(x.at(i)<x.at(i-1)&&x.at(i)<x.at(i+1)){
      e=d/x.at(i);
      d=d%x.at(i);
    }
    else if(x.at(i)>x.at(i-1)&&x.at(i)>x.at(i+1)){
      d=d+x.at(i)*e;
      e=0;
    }
  }
  cout<<d+e*x.at(n-c-1)<<endl;
}