#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
int a[N],b[N];
int main()
{
    int n,k;cin>>n>>k;
    for(int i=0;i<n;i++) cin>>a[i];
    while(k--)
    {
        memset(b,0,sizeof b);
        int mx=n;
        for(int i=0;i<n;i++)
        {
            mx=min(mx,a[i]);
            int l=max(0,i-a[i]);
            int r=min(n,i+a[i]+1);
            b[l]++;b[r]--;
        }
        if(mx>=n) k/=2;
        for(int i=0;i<n-1;i++)
        {
            b[i+1]+=b[i];
        }
        for(int i=0;i<n;i++) a[i]=b[i];
    }
    for(int i=0;i<n;i++) cout<<a[i]<<" ";

    return 0;
}
