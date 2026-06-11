#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x;
  cin>>x;
  if(400<=x&&x<600){
    cout<<'8';
  } else if(600<=x&&x<800){
    cout<<'7';
  } else if(800<=x&&x<1000){
    cout<<'6';
  } else if(1000<=x&&x<1200){
    cout<<'5';
  } else if(1200<=x&&x<1400){
    cout<<'4';
  } else if(1400<=x&&x<1600){
    cout<<'3';
  } else if(1600<=x&&x<1800){
    cout<<'2';
  } else {
     cout<<'1'<<endl;
  }
}