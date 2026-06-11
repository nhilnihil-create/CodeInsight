#include<bits/stdc++.h>
#define prArr(Arr,n) for(int _=0;_<n;_++)   cout<<(Arr)[_]<<" ";
#define f first
#define s second
using namespace std;
const int INF=(int)0x3f3f3f3f;
const int MOD=(int)1e9+7;
const double eps=1e-9;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,l,mn=INF,sum=0;
    cin>>n>>l;
    for(int i=1;i<=n;i++)
        sum+=l+i-1;
    for(int i=l;i<=l+n-1;i++)
        if(abs(i)<abs(mn))
            mn=i;
    cout<<sum-mn;
    return 0;
}

