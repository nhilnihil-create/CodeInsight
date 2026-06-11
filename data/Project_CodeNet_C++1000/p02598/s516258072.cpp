#include<bits/stdc++.h>
using namespace std;
bool isgood(long long int mid,vector<int> &arr,long long int k)
{
    int count=0;
    if(mid==0)
        return false;
    for(long long int i=0;i<arr.size();i++)
    {
        if(arr[i]<=mid)
            continue;
        else
        {
            long long int x=arr[i]/mid;
            long long int rem=arr[i]%mid;
            if(rem==0)
            {
                count+=x-1;
            }
            else
            {
                count+=x;
            }
        }
    }
    if(count<=k)
    {
        return true;
    }
    else
        return false;
}
int main()
{
    long long int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    long long int start=0,end=1000000020;
    while(start<end)
    {
        long long int mid=start+ (end-start)/2;
        if(isgood(mid,arr,k))
        {
            end=mid;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<start<<endl;

}
