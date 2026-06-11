#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int n,i,x1=0,a;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>a;
        if(i%2!=0 && a%2!=0)
        {
            x1++;
        }
    }
    cout<<x1;
    }
