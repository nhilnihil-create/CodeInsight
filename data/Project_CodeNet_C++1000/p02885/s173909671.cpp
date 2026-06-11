#include<iostream>
using namespace std;
int main()
{
   int r,t,s;
   cin>>r>>t;
   s=t+t;
   if(s>=r){cout<<"0"<<endl;}
   else{cout<<r-s<<endl;}
}