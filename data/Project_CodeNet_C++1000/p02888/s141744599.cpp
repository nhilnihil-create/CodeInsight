#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[2000],i,j,k,countr=0;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            int sum=a[i]+a[j];
            for(k=j+1;k<n;k++)
            {
                if(a[k]<sum)
                {
                    countr++;
                }
            }
        }
    }
    cout << countr;
}
