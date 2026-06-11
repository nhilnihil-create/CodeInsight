#include<bits/stdc++.h>
using namespace std;
int Binary_Search(int a[], int l, int r, int key)
{
    int mid,ans=-1;
    while(l<=r)
    {
        mid=l+(r-l)/2;
        if(a[mid]>=key)
        {
            ans=mid;
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    int a[n],i,j;
    for(i=0;i<n;i++)
    {
        cin >> a[i];
    }
    int countr=0;
    sort(a, a+n);
    //int result=Binary_Search(a, 0, n-1, 10);
    //cout << result;
    for(i=0;i<n-2;i++)
    {
        for(j=i+1;j<n-1;j++)
        {
            int sum=a[i]+a[j];
            int result;
            result=Binary_Search(a,j+1, n-1, sum);
            if(result!=-1)
            {
                //cout << result << endl;
                countr+=(result-j-1);
            }
            else
            {
                countr+=(n-j-1);
            }
        }
    }
    cout << countr;
}
