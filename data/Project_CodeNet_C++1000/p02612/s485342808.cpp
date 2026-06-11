#include<iostream>
#include<cmath>
using namespace std;
int main(){
int X;
cin>>X;
int k=ceil((float)X/1000);
k=k*1000;
cout<<k-X;


return 0;
}
