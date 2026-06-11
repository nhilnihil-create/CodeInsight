#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
int n,l,r,x;
    vector<int>b(200009),a(200009);
int main()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i&1&&a[i]&1)
            ans++;
    }
    cout<<ans;
}
