#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,i,c=0,d;
    cin>>a;

    for(i=1;i<=9;i++)
    {
        if(a%i==0)
        {
            d=a/i;
            {
                if(d>0 && d<10)
                    c++;
            }
        }
    }
    if(c>=1)
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
