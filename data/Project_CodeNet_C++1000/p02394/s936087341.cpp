#include<iostream>
using namespace std

;

int main(){

int W,H,x,y,r,s1,s2;

cin>>W>>H>>x>>y>>r;

if (x-r>=0 && x+r<=W){

s1=0;

} else{

s1=1;

}

if (y-r>=0 && y+r<=H){

s2=0;} else{

s2=1;

}


if (s1==0 && s2==0){

cout<<"Yes"<<"\n";

} else{

cout<<"No"<<"\n";

}

return 0;

}