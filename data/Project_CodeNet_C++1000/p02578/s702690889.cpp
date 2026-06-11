#include<iostream>
using namespace std;

int main(){
  int n;
  cin>>n;
  int a[n];
  int i;
  
  for(i=0;i<n;i++)
    cin>>a[i];
  long long int stools= 0;
 long int diff;
  int maxi=0;
 for(i=0;i<n;i++)
 {
   maxi = max(maxi,a[i]);
     diff = (maxi-a[i]); 
    stools+=diff;

 }
  cout<<stools;
  
  
  
 return 0; 
}
