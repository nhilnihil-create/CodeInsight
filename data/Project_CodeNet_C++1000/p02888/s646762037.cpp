#include<iostream>
#include<algorithm>
using namespace std;
const int N=2e3+10;
int a[N];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1);
    long long res=0;
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        int l=j,r=n;
        while(l<r)
        {
            int mid=l+r+1>>1;
            if(a[mid]<a[i]+a[j])    l=mid;
            else r=mid-1;
        }
        res+=l-j;
    }
    cout<<res;
}