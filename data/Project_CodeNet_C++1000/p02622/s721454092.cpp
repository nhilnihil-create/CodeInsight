#include<bits/stdc++.h>
using namespace std;
#define oo (long long)1e18
#define ll long long
#define setdp memset(dp,-1,sizeof(dp))
const ll mod = 1e9+7;
void _IOS(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.sync_with_stdio(0);}
#define PI 3.14159265359
ll n,l,r,x;
    int b[200009],a[200009];
int main()
{
    string s,t;
    cin>>s>>t;
    n=s.length();
    int ans=0;
    for(int i=0;i<n;i++)
        if(s[i]!=t[i])
            ans++;
        cout<<ans;
}
