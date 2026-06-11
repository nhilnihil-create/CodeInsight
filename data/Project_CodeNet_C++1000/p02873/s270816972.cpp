#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define f first
#define s second
long long int power(long long int x,long long int y,long long int mod)
{
    long long int res=1LL;
    while(y>0)
    {
        if(y&1) res=(res*x)%mod;
        y>>=1;
        x=(x*x)%mod;
    }
    return res;
}

/*bool compare(pair<long long int,long int> a,pair<long long int,long int> b)
{
    return a.s<b.s;
}*/

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t=1;
    while(t--)
    {
        string s;
        cin>>s;
        long int n=s.length()+1;
        long long int a[n]={0};
        for(long int i=0;i<n-1;i++)
        {
            if(s[i]=='<')
            a[i+1]=a[i]+1;
        }
        for(long int i=n-2;i>=0;i--)
        {
            if(s[i]=='>')
            a[i]=max(a[i],a[i+1]+1);
        }
        long long int ans=0;
        for(long int i=0;i<n;i++)
        ans+=a[i];
        cout<<ans<<endl;
    }
	// your code goes here
	return 0;
}
