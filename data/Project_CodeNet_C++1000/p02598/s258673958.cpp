#define lld long long int
#include<bits/stdc++.h>
using namespace std;
lld n,k;
lld a[200001];

lld fin(lld num,lld length)
{
    lld start=1,end=1000000000,ans;
    while(start<=end)
    {
        double mid=start+(end-start)/2;
        if(ceil(num/mid)<=length)
        {
            ans=mid-1;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    return ans;
}


bool isPossible(lld length)
{
    lld times=0;
    for(lld i=0;i<n;i++)
    {
        if(a[i]<length)
        {
            continue;
        }
        else
        {
            
            times=times+fin(a[i],length);
                //cout<<"in = "<<times<<endl;
                if(times>k)
                {
                    return false;
                }
        }
        //cout<<"i = "<<i<<" times = "<<times<<endl;
    }
    return true;
}


int main()
{
    cin>>n>>k;
    lld m=0;
    for(lld i=0;i<n;i++)
    {
        cin>>a[i];
        m=max(m,a[i]);
    }
    lld start=1,end=m,ans;
    while(start<=end)
    {
        lld mid=start+(end-start)/2;
        //cout<<"mid = "<<mid<<endl;
        if(isPossible(mid))
        {
            //cout<<"ans = "<<mid<<endl;
            ans=mid;
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    cout<<ans<<endl;
}