#include<iostream>
using namespace std;
int main()

{
  int n,a[105],i,c=0;
  cin>>n;
  for(i=1;i<=n;i++)
  {
      cin>>a[i];
  }

  for(i=1;i<=n;i=i+2)
  {

     if(a[i]%2==1)
     {
         c++;
     }
  }
  cout<<c<<endl;

    return 0;
}
