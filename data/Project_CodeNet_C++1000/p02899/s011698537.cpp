#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pb push_back
const int maxn=2e5+10;
const int mod=1e9+7;
int a[maxn];
int f[maxn];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
        cout<<f[i]<<" ";




}