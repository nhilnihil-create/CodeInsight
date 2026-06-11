
#include <iostream>
#include<algorithm>

using namespace std;

int main()
{
    long long a,b,k,i,j,m;
    cin>>a >>b >>k ;
    if(a==0 && b==0)
    {
        cout<<a <<" "<<b <<endl;
    }else
    {
      if(k<=a)
    {
        cout<<a-k<<" "<< b <<endl;
    }else 
    {
        m=(k-a);
     cout<<0<<" "<<b- min(b,m);  
    }  
    }
    return 0;
}