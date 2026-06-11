#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a,a);
}
int findGCD(int arr[], int n)
{
    int result=arr[0];
    for (int i=1;i<n;i++)
    {
        result = gcd(arr[i], result);

        if(result == 1)
        {
           return 1;
        }
    }
    return result;
}
int main()
{
    int k;
    long long int s=0;
    cin>>k;
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=k;j++)
        {
            for(int l=1;l<=k;l++)
            {
                int arr[]={i,j,l};
                s=s+findGCD(arr, 3);
            }
        }
    }
    cout<<s;
    return 0;
}
