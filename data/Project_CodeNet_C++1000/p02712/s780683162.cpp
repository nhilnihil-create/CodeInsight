#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
     long long int a,b,k,sum=0,i;
     cin>>a;
     for(i=1;i<=a;i++)
     {
          if(i%3==0 || i%5==0)
          {
              continue;
          }
            else{sum=sum+i;}
     }
     cout<<sum<<endl;
     return 0;
}
