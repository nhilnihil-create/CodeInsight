#include <iostream>
#define endl '\n'
using namespace std;
int main()
{   int t;
    cin>>t;
    if(t<=599 && t>=400){
        cout<<"8";
    }
    else if(t<=799 && t>=600){
        cout<<"7";
    }
  else   if(t<=999 && t>=800){
        cout<<"6";
    }
    
   else  if(t<=1199 && t>=1000){
        cout<<"5";
    }
   else  if(t<=1399 && t>=1200){
        cout<<"4";
    }
  else  if(t<=1599 && t>=1400){
        cout<<"3";
    }
    else  if(t<=1799 && t>=1600){
        cout<<"2";
    }
    else  if(t<=1999 && t>=1800){
        cout<<"1";
    }
}
