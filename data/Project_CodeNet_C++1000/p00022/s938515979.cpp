#include<iostream>
using namespace std;

int max(int a, int b)
{
  return (a>b)? a : b ;
}
int main()
{
 int n, x, y, a[5001];
 while(cin>>n, n)
 {
  for(int i=0; i<n; i++)
  {
   cin>>a[i];
   }
  x=a[0];
 for(int i=0; i<n; i++)
 {
  int sum=0;
  for(int j=i; j<n; j++)
   {
    sum += a[j];
     x = max( x, sum );
    }
   }
  cout<<x<<endl; 
 }
 }
   