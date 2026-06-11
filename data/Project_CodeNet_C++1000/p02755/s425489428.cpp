#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int i,j,k,a,b;
    cin>>a>>b;
    k=max((100*a)/8,(100*b)/10);
    for(i=1;i<=1009;i++)
    {
        if((i*8)/100==a && (i/10)==b)
        {
            cout<<i;
            return 0;
        }
        else
        {
            j=1;
        }  
    }
    if(j==1)
    {
        cout<<-1;
        return 0;
    }
}