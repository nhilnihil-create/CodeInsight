#include<iostream>
using namespace std;
const int maxn=2e5+10;
int a[maxn],n,k;
bool judge(int x){
    int cnt=0;
    for(int i=0; i<n; i++)
       cnt+=(a[i]-1)/x;
    return cnt<=k;
}
int main()
{
    int l=1,r=0;
    cin>>n>>k;
    for(int i=0;i<n;i++) 
      cin>>a[i],r=max(r,a[i]);
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(judge(mid))
           r=mid-1;
        else l=mid+1;
    }
    cout<<l;
    return 0;
}
