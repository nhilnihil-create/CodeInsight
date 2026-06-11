#include<iostream>
using namespace std;
long long int maximum(long long int a,long long int b)
{
   long long int c=a>b?a:b;
    return c;
}
main ()
{
     long long int a,b,c,d,sum1,sum2,sum3,sum4;
     long long int temp;
    cin>>a>>b>>c>>d;
    sum1=a*c;
    sum2=a*d;
    sum3=b*c;
    sum4=b*d;
    temp=maximum(sum1,sum2);
    temp=maximum(temp,sum3);
    temp=maximum(temp,sum4);
    cout<<temp<<endl;



}
