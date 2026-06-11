#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[101]={};
    for (int i=1;i<=9;i++)
    {
        for (int j=1;j<=9;j++)
        {
            a[i*j]=1;
        }
    }
    if (a[n]==1)
    printf("Yes\n");
    else
    printf("No\n");
    return 0;
}