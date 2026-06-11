#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,c,k,sum=0;
    cin>>a>>b>>c>>k;

    while(k--)
    {
        if(a>0)
        {
            sum=sum+1;
            a--;
        }
        else if(b>0)
        {
            sum=sum+0;
            b--;
        }
        else if(c>0)
        {
            sum=sum-1;
            c--;
        }
    }

cout<<sum<<endl;



    return 0;
}