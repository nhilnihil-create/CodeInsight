#include<stdio.h>
#include<iostream>
#include<algorithm>

using namespace std;

int main(){


int W,H,x,y,r;

cin>>W>>H>>x>>y>>r;

if(x==0||y==0||x==W||y==H){
  cout<<"No"<<endl;
  return 0;
}
else if(x+r>W || x-r<0){
  cout<<"No"<<endl;
  return 0;
}
else if(y+r>H || y-r<0){
  cout<<"No"<<endl;
  return 0;
}
else cout<<"Yes"<<endl;

return 0;

}