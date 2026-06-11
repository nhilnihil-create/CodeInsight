#include<bits/stdc++.h>
using namespace std;
int main()
{
  int n,i;
  cin>>n;
  i = n%10;
  if(i==2||i==4||i==5||i==7||i==9)
    cout<<"hon";
  else if(i==0||i==1||i==6||i==8)
    cout<<"pon";
  else
    cout<<"bon";
  return 0;
 
}