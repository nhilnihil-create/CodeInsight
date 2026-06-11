#include<iostream>
using namespace std;
int main (void)
{
 int n;
  cin>>n;
  n=n%10;
  if(n==3){cout<<"bon";}
  else if(n==2||n==4||n==5||n==7||n==9){cout<<"hon";}
  else cout<<"pon";
 
}
 