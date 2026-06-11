#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    long long n,a[200],i,j,total=0,min=2000000000;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(j=1;j<=a[n];j++)
    {
        total=0;
        for(i=1;i<=n;i++)
        {
            total+=((j-a[i])*(j-a[i]));
        }
        if(total<min)
        {
            min=total;
        }
    }
    cout<<min<<endl;
    return 0;
}