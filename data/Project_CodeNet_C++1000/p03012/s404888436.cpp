#include<iostream>
#include<algorithm>
using namespace std;


int main(void)
{
  int n,w[100],i,j,k,a,b,ans,s1,s2;
  cin>>n;
  s1=0;s2=0;
  for(i=0;i<n;i++)
  {
    cin>>w[i];
  }
  i=0;
  j=n-1;
  while(1)
  { 

    if(s1<=s2){s1+=w[i];i++;}
    else{s2+=w[j];j--;}
    
    if(i==j)
    { 
      if(s1<=s2){s1+=w[i];i++;}
      else{s2+=w[j];j--;}
      break;
    }

  }
  cout<<abs(s1-s2)<<endl;
  
}