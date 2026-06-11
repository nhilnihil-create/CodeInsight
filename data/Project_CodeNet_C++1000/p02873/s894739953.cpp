#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size()+1;
    int a[n];
    for(int i=0;i<n;++i) a[i]=0;
    for(int i=0;i<(n-1);++i)
    {
        if(s[i]=='<')
        {
            a[i+1]=a[i]+1;
        }
    }
    for(int i=(n-1);i>=0;--i)
    {
        if(s[i]=='>')
        {
            a[i]=max(a[i],a[i+1]+1);
        }
    }
    int sum=0;
    for(int i=0;i<n;++i) sum+=a[i];
    cout<<sum;
    return 0;
}
