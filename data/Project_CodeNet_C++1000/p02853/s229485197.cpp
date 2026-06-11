#include <bits/stdc++.h>
using namespace std;
int main(){
  int x,a=0;
  cin>>x;
  if(x==3)a+=100000;
  if(x==2)a+=200000;
  if(x==1)a+=300000;
  cin>>x;
  if(x==3)a+=100000;
  if(x==2)a+=200000;
  if(x==1)a+=300000;
  if(a==600000)a+=400000;
  cout<<a<<endl;
}