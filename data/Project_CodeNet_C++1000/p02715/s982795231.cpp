#include<iostream>
#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int n, k, m=1e9+7, cnt[100009], f[100009],ph[100009];
vector<int> v[100009];
ll ans;
ll fastpower(ll b, ll p)
{
    if(p == 0)
        return 1 ;
    return p % 2 == 0 ? fastpower((b * b) % m, p / 2) : (b * fastpower((b * b) % m, p / 2) % m) % m;
}
void solve()
{
    for(int i=1; i<=k; i++)
    {
        for(int j=i; j<=k; j+=i)
            v[j].push_back(i);
        cnt[i]=k/i;
        if(i==1)
            ph[i]=1;
        else if(v[i].size()==2)
            ph[i]=-1;
        else if(i%(1LL*v[i][1]*v[i][1])==0)
            ph[i]=0;
        else
            ph[i]=-ph[i/v[i][1]];
    }
    for(int i=1; i<=k; i++)
        for(auto j : v[i])
            f[j]=(1LL*f[j]+1LL*fastpower(cnt[i],n)*ph[i/j])%m;
    for(int i=1; i<=k; i++)
    {
        ans+=1LL*f[i]*i;
        ans%=m;
    }
    cout<<(ans+m)%m;
}
int main()
{
    IO
    cin>>n>>k;
    solve();
}
