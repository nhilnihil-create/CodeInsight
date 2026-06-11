//Author - Rahil Malhotra
#include <bits/stdc++.h>
using namespace std;
 
template <typename T> void print(T t) { cout<<t<<endl; }
template<typename T, typename... Args> void print(T t, Args... args) { cout<<t<<" "; print(args...); }
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
#define int long long
#define double long double

int n,k;
int arr[505];
int check(int val)
{
    multiset<int>ms;
    for(int i=0;i<n;i++)
        if(arr[i]%val!=0)
            ms.insert(arr[i]%val);
    int ctr=0;
    while(ms.size())
    {
        if(ms.size()==1)
            return 0;
        int a=*ms.begin();
        int b=*ms.rbegin();
        ms.erase(ms.find(a));
        ms.erase(ms.find(b));
        b=val-b;
        while(true)
        {
            int mini=min(a,b);
            ctr+=mini;
            a-=mini;
            b-=mini;
            if(a==b)
                break;
            if(!ms.size())
                return 0;
            if(a>0)
            {
                b=*ms.rbegin();
                ms.erase(ms.find(b));
                b=val-b;
            }
            else
            {
                a=*ms.begin();
                ms.erase(ms.find(a));
            }
        }
    }
    return ctr<=k;
}
int32_t main()
{
    IOS;
    cin>>n>>k;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    int ans=1;
    for(int i=1;i*i<=sum;i++)
    {
        if(sum%i==0)
        {
            if(check(i))
                ans=max(ans,i);
            if(check(sum/i))
                ans=max(ans,sum/i);
        }
    }
    print(ans);
}