//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double
 
int n;
int arr[100005];
int tablemax[(int)log2(150005)+2][150005];
int floorlog[150005];
int maxi(int start,int end)
{
    int p=floorlog[end-start+1];
    return max(tablemax[p][start],tablemax[p][end-(1<<p)+1]);
}

int32_t main()
{
    IOS;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=0;(1<<i)<150005;i++)
    {
        for(int j=(1<<i);j<150005 && j<(1<<(i+1)); j++)
            floorlog[j]=i;
    }
    for(int i=1;i<=n;i++)
        tablemax[0][i]=arr[i];

    for (int j=1;(1<<j)<=n;j++) 
        for (int i=1;(i+(1<<j)-1)<=n;i++)
            tablemax[j][i]=max(tablemax[j-1][i],tablemax[j-1][i+(1<<(j - 1))]);

    int ans=0;
    for(int i=1;i<=n;i++)
    {
        int low=i+1;
        int high=n;
        while(low<high)
        {
            int mid=(low+high)/2;
            if(maxi(i+1,mid)<arr[i])
                low=mid+1;
            else
                high=mid;
        }
        low=min(low,n);
        int low1=1;
        int high1=i-1;
        while(low1<high1)
        {
            int mid=(low1+high1+1)/2;
            if(maxi(mid,i-1)<arr[i])
                high1=mid-1;
            else
                low1=mid;
        }
        if(i==n && maxi(low1,i-1)<arr[i])
            continue;
        if(i==1 && maxi(i+1,low)<arr[i])
            continue;

        //print(i,low,low1,maxi(i+1,low),maxi(low1,i-1));
        if(maxi(i+1,low)<arr[i] && maxi(low1,i-1)<arr[i])
            continue;
        if((i<n && maxi(i+1,low)>=arr[i]) && (i==1 || maxi(low1,i-1)<arr[i]))
        {
            int low2=low+1;
            int high2=n;
            while(low2<high2)
            {
                int mid=(low2+high2)/2;
                if(maxi(low+1,mid)<arr[i])
                    low2=mid+1;
                else
                    high2=mid;
            }
            if(low2<=n && maxi(low+1,low2)<arr[i])
                low2++;
            ans+=arr[i]*i*(low2-low);
            continue;
        }
        if((i==n || maxi(i+1,low)<arr[i]) && (i!=1 && maxi(low1,i-1)>arr[i]))
        {
            int low2=1;
            int high2=low1-1;
            while(low2<high2)
            {
                int mid=(low2+high2+1)/2;
                if(maxi(mid,low1-1)<arr[i])
                    high2=mid-1;
                else
                    low2=mid;
            }
            if(low1==1)
                low2=0;
            else if(maxi(low2,low1-1)<arr[i])
                low2=0;
            ans+=arr[i]*(n-i+1)*(low1-low2);
            continue;
        }
        int low2=low+1;
        int high2=n;
        while(low2<high2)
        {
            int mid=(low2+high2)/2;
            if(maxi(low+1,mid)<arr[i])
                low2=mid+1;
            else
                high2=mid;
        }
        if(low2<=n && maxi(low+1,low2)<arr[i])
            low2++;
        ans+=arr[i]*(i-low1)*(low2-low);

        low2=1;
        high2=low1-1;
        while(low2<high2)
        {
            int mid=(low2+high2+1)/2;
            if(maxi(mid,low1-1)<arr[i])
                high2=mid-1;
            else
                low2=mid;
        }
        if(low1==1 || maxi(low2,low1-1)<arr[i])
            low2=0;
        ans+=arr[i]*(low-i)*(low1-low2);
    }
    print(ans);
}