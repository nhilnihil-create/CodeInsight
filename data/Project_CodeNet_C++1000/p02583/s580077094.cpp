#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            for(int k=0;k<j;k++)
            {
                if(arr[i]!=arr[j] && arr[j]!=arr[k] && arr[k]!=arr[i])
                {
                    if(arr[j]+arr[k]>arr[i]) sum++;
                }
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
