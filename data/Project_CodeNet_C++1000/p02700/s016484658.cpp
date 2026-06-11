#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d,t,s;
  cin>>a>>b>>c>>d;
  if(a%d==0){
    t=a/d;
  }else{
    t=a/d+1;
  }
  if(c%b==0){
    s=c/b;
  }else{
    s=c/b+1;
  }
  if(t>=s){
    cout<<"Yes";
  }else{
    cout<<"No";
  }
}