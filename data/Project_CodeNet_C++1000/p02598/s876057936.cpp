#define IO ios::sync_with_stdio(false);cin.tie();cout.tie(0)
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=200010;
int a[N],n,k;
bool check(int mid)
{
    ll res=0;
    for(int i=1;i<=n;i++) res+=(a[i]+mid-1)/mid-1;
    return res<=k;
}
int main()
{
    IO;
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    int l=1,r=1e9;
    while(l<r)
    {
        int mid=l+r>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    cout<<l<<endl;
    return 0;
}