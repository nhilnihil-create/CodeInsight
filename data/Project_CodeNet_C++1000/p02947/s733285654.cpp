#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define pb push_back
#define vl vector
#define ff first
#define ss second
using namespace std;
int main()
{
    ll a,b,i,j,n,t,c,m;
    cin>>n;
    vl<string> s(n);
    for(i=0;i<n;i++) cin>>s[i];
    for(i=0;i<n;i++) sort(s[i].begin(),s[i].end());
    sort(s.begin(),s.end());
    ll count=0;
    ll ans=0;
    for(i=1;i<n;i++)
    {
        if(s[i]==s[i-1]) count++;
        else
        {
            ans+=((count)*(count+1))/2;
            count=0;
        }
    }
    ans+=((count)*(count+1))/2;
    cout<<ans;
}