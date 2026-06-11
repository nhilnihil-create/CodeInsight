#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n]={};
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if (i)
        b[i]=a[i]+b[i-1];
        else
        b[i]=a[i];
    }
    int sum1=0;
    for (int i=1;i<n;i++)
    {
        sum1=sum1+(a[i]*b[i-1]);
    }
    printf("%d\n",sum1);
    return 0;
}