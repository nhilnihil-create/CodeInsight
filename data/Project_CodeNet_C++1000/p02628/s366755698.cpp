#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n+1],ar[n+1];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
            int aa =arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=aa;
            }
        }
    }
    int sum=0;
    for(int i=0;i<k;i++)
    {
        sum+=arr[i];
    }
    printf("%d\n",sum);
    return 0;
}