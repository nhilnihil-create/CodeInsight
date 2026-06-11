#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int n,d,a[20][20],i,j,k,sum,integer=0;
    double sq;
    cin>>n>>d;
    for(i=0;i<n;i++)
    {
        for(j=0;j<d;j++)
        {
            cin>>a[i][j];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                continue;
            sum=0;
            for(k=0;k<d;k++)
            {
                sum=sum+pow((a[i][k]-a[j][k]),2);
            }
            sq=sqrt(sum);
            //cout<<"sum "<<sum<<" sq "<<sq<<"\n";
            sq=sq/(int)sq;
            if(sq==1)
                integer++;
        }
    }
    cout<<integer/2;

    return 0;
}
