#include<bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int n,k;
    cin>>k>>n;
    long long int ans=0;
    long long int prev;
    long long int first,last;
    for(long long int i=0;i<n;i++)
    {
        long long int a;
        cin>>a;
        if(i==0)
        first=a;
        if(i==n-1)
        last=a;
        if(i!=0)
        ans=max(ans,a-prev);
        prev=a;
    }
    ans=max(ans,(k-last)+first);
    cout<<k-ans<<"\n";
}