#include<iostream>
using namespace std;
int main()
{
    int n,x,s=0;
    cin>>n;
    while(n!=0)
    {
       x=n%10;
       if(x==7)
       {
          s++;
          break;
       }  
       n/=10;     
    }
    if(s>0)
    {
        cout<<"Yes\n";
    }
    else
    {
        cout<<"No\n";
    }
    return 0;
}