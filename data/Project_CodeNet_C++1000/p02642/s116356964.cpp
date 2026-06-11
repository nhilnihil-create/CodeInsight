#include<bits/stdc++.h>
#define ll long long int
#define ull unsigned long long int
#define mod 1000000007
using namespace std;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    int a[n];
    bool p[1000001];
    for (int i=0;i<1000001;i++) p[i]=0;
    map<int,int> cnt;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        p[a[i]]=1;
        cnt[a[i]]++;
    }
    sort(a, a+n);
    for(int i=0;i<n;i++)
    {
        if(p[a[i]])
        {
            for(int j=2*a[i];j<=a[n-1];j+=a[i])
            {
                p[j]=false;
            }
        }
    }
    for(auto x:a)
    {
        if(cnt[x]>1)
        {
            p[x]=0;
        }
    }
    int ans=0;
    for (auto x: p)
    {
        if (x) ans++;
    }
    cout<<ans;
    return 0;
}