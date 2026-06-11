#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,i,j,cool;
    cin>>n;
    for(j=n;;j++)
    {
         cool=0;
        for(i=2;i<=j/2;i++)
        {

            if(j%i==0)
            {
                cool=1;
            }
         }
    if(cool==0)
        break;
    }
    cout<<j;
return 0;}
