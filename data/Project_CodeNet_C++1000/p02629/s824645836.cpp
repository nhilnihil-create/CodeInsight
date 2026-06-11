#include<iostream>
#include<algorithm>
using namespace std;
int main (void)
{ 
  long long int n;
  char s[20];
  cin>>n;
  int i=0;
  
 while(n>0)
 { 
   n--;
   s[i]=(n%26)+'a';
   n=n/26;
   i++;
 }
  n=i;
  for(i=0;i<n;i++)
  {
    cout<<s[n-i-1];
  }
  cout<<endl;
}