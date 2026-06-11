#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a =n%100%10;
  if(a==3)
    cout<<"bon"<<endl;
  else if(a==2||a==4||a==5||a==7||a==9)
    cout<<"hon"<<endl;
  else if(a==0||a==1||a==6||a==8)
    cout<<"pon"<<endl;
}