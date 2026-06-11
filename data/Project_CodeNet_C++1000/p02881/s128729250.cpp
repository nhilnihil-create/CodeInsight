#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n;
    cin>>n;
    long long int mi=100000000000000;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            long long int d;
            d=i+n/i-2;
            mi=min(mi,d);
        }

    }
    cout<<mi<<endl;
   return 0;
}