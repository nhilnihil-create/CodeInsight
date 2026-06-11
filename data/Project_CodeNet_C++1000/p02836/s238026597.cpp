#include<bits/stdc++.h>
#define ll long long 
#define ld long double
#define vl vector
#define pb push_back
#define ff first
#define ss second
using namespace std;

int main()
{
    ll n,m,i,a=0,b=0,k,t,j;
    string s;
    cin>>s;
    string s1,s2;
    if(s.size()%2)
    {
        n=s.size()/2;
        s1=s.substr(0,n);
        s2=s.substr(n+1,n);
    }
    else
    {
        n=s.size()/2;
        s1=s.substr(0,n);
        s2=s.substr(n,n);
    }
    reverse(s2.begin(),s2.end());
    ll ans=0;
    for(i=0;i<s2.size();i++) if(s1[i]!=s2[i]) ans++;
    cout<<ans;
}