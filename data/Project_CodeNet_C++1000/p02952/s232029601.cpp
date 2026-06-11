#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{ 
 int n,i,j,ans;
  
 cin>>n;
  if(n<10){cout<<n;return 0;}
  j=0;i=1;
 while(n/i>=1)
 {
   j++;
   i*=10;
 }
 
  ans=0;
  
  if(j%2!=0){ans=n-i/10+1; j=j-2;i=i/100;}
  else{j=j-1;i=i/10;}
  
  while(j!=0)
  { 
   
    if(j%2==1){ans=ans+i-1;}
    else{ans=ans-i+1;}
    i=i/10;
    j--;
  }
  cout<<ans;
}