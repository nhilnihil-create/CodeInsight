#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,j;
    cin>>n;
    for(i=n;;i++)
    {
        int f=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0) f=1;
        }
        if(f==0) break;
    }
    cout<<i;
    return 0;
}
