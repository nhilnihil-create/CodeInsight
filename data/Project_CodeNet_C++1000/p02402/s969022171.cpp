#include<iostream>
using namespace std;

int main(){

long long a,i,x,y,z;

int n;

cin>>n;

x=1000000;
y=-1000000;
z=0;

for(i=0;i<n;i++){

cin>>a;

if(a<x)x=a;
if(a>y)y=a;
z+=a;

}

cout<<x<<" "<<y<<" "<<z<<"\n";

return 0;

}