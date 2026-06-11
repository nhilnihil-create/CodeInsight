#include <bits/stdc++.h>
using namespace std ;
int main()
{
  int i,a,b,n,c=0;
    cin>>n;
    cin>>a>>b;
    for(i=a;i<=b;i++){
    if(i%n==0)
    {
      c++;
    }
    }
    if(c>=1)
        cout<<"OK"<<endl;
    else
        cout<<"NG"<<endl;
 
 
}
