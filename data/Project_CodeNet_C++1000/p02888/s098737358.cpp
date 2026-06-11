#include <bits/stdc++.h>
#define ll long long int
#define dbg(x) cout<<"( "<<#x<<" -> "<<x<<" )"<<endl;
using namespace std;
/*
int BS(int arr[],int len,int ele)
{
    int low=0,high=len;
    while (low<high)
    {
        int mid=low+(high-low)/2;
        if (arr[mid]>ele)
        high=mid;
        else
        low=mid+1;
    }
    return low;
}
*/
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    a[n]=INT_MAX;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+(n+1));
    ll sum1=0;
    for (int i=0;i<n-2;i++)
    {
        for (int j=i+1;j<n-1;j++)
        {
            for (int k=j+1;k<n;k++)
            {
                if (a[i]<(a[j]+a[k]) && a[j]<(a[i]+a[k]) && a[k]<(a[i]+a[j]))
                sum1++;
            }
        }
    }
    printf("%lld\n",sum1);
    return 0;
}