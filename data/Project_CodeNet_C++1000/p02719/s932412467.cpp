#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long N,K,a,b;
    cin>>N>>K;
    if(N%K==0)
    {
        cout<<0<<endl;
    }
    else
    {
         a=N%K;
         b=abs(K-a);
         if(a<b)
         {
             cout<<a<<endl;
         }
         else
         {
             cout<<b<<endl;
         }
    }
    return 0;
}
