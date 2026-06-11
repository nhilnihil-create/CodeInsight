#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    long long x,i,s,j;
    cin>>x;
    if(x==2)
    {
        cout<<2<<endl;
        return 0;
    }
    else
    {
        for(i=x;i>=x;i++)
        {
            s=0;
            for(j=2;j<=sqrt(i);j++)
            {
                if(i%j==0)
                {
                    s++;
                }
            }
            if(s==0)
            {
                cout<<i<<endl;
                return 0;
            }
        }
    }
}