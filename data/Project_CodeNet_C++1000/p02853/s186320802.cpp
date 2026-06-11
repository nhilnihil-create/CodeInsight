#include<bits/stdc++.h>
using namespace std;
int main()
{
  int a,b;
  cin>>a>>b;
 
  if((a==1)&&(b==1))
    	cout<<1000000;
  else if((a==1)&&(b==2))
    	cout<<500000;
  else if((a==1)&&(b==3))
    	cout<<400000;
  else if((a==2)&&(b==1))
    	cout<<500000;
  else if((a==2)&&(b==2))
    	cout<<400000;
  else if((a==2)&&(b==3))
    	cout<<300000;
  else if((a==3)&&(b==1))
    	cout<<400000;
  else if((a==3)&&(b==2))
    	cout<<300000;
  else if((a==3)&&(b==3))
    	cout<<200000;
  else if((a==1)&&(b>3))
    	cout<<300000;
  else if((a==2)&&(b>3))
    	cout<<200000;
  else if((a==3)&&(b>3))
    	cout<<100000;
   else if((b==1)&&(a>3))
    	cout<<300000;
  else if((b==2)&&(a>3))
    	cout<<200000;
  else if((b==3)&&(a>3))
    	cout<<100000;
  else 
    	cout<<0;
  
  
  
}
