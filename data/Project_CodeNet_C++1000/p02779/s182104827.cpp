// Example program
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
  int n;
  cin >>n;
  int a[n];
  for(int i =0;i<n;i++) cin >>a[i];
  sort(a,a+n);
  bool x=0;
  for(int i=0;i<n-1;i++)
  if(a[i] ==a[i+1]) {
      x=1;
      break;}
  
 if(!x)cout<<"YES\n";
  else cout <<"NO\n";
      return 0;
}
