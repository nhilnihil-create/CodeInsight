#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define f first
#define s second
#define go ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
/*bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second);
} */
ll sum[500005];
int main()
{
     ll n;
     string str;
     cin>>str;
     n=str.size();
     for(int i=0;i<n;i++)
     {
         if(str[i]=='<')
            sum[i+1]=sum[i]+1;
     }
     for(int i=n-1;i>=0;i--)
     {
         if(str[i]=='>')
            sum[i]=max(sum[i+1]+1,sum[i]);
     }
     ll ans=0;
     for(int i=0;i<=n;i++)
        ans+=sum[i];
     cout<<ans<<endl;
}

