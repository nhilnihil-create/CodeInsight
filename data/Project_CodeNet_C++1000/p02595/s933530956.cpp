#include<cmath>
#include<iostream>
using namespace std;
int main()
{
    int a=0,k,n,d;
    long long int x,y;
    double z;
    cin>>n>>d;
    int i;
    for( i=0; i<n; i++)
    {
        cin>>x>>y;
        if(x==0&&y==0)
        {
            k=0;
            goto m;
        }

        z=sqrt(((x+y)*(x+y))-2*x*y);
        k=ceil(z);
m:
        if(k<=d)
            a++;
    }
    cout<<a;
}
