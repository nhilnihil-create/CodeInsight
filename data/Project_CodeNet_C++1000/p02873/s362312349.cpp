#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

    string s;
    cin>>s;
    int n=s.size();
    ll arr[n+5]={0};
    for(int i=0;i<n;i++)
    {
        if(s[i]=='<')
        {
            arr[i+1]=arr[i]+1;
        }
    }
    for(int i=n-1;i>=0;i--)
    {
        if(s[i]=='>')
        {
            arr[i]=max(arr[i+1]+1,arr[i]);
        }
    }
    ll ans=0;
    for(int i=0;i<n+1;i++)
    {
        ans+=arr[i];
    }
    cout<<ans<<endl;
}
