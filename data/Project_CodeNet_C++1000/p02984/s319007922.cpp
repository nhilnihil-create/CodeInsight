#include<bits/stdc++.h>
typedef long long ll;
const ll mod=1e9+7;
const ll inf=0x3f3f3f3f;
const int N=2e5+5;
using namespace std;
int a[N];
int b[N];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i&1) b[1]+=a[i];
        else b[1]-=a[i];
    }
    for(int i=2;i<=n;i++)
    {
        b[i]=(b[i-1]-a[i-1])*(-1)+a[i-1];
    }
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    return 0;
}
