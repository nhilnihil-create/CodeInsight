#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int rem=n%10;
  if(rem==2||rem==4||rem==5||rem==7||rem==9)
    cout<<"hon\n";
  else if(rem==3)
    cout<<"bon\n";
  else
    cout<<"pon\n";
}
