#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int sum=0,i,j,n,p,x1=0,flag=0;
    cin>>n;
    p=sqrt(n);
    for(i=1; i<=p; i++)
    {
        if(n%i==0 && i<10 && (n/i)<10)
        {
            flag=1;
            break;
        }
    }
    if(flag==1)
    {
        cout<<"Yes";
    }
    else
        cout<<"No";
    }
