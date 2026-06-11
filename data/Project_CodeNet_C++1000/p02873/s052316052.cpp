#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int main()
{
    string s; cin>>s; ll f1=0,f2=0;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='<') f1=1;
        if(s[i]=='>') f2=1;
    }
    if(f1==0 || f2==0)
    {
        ll n=s.size();
        cout<<(n*(n+1))/2;
        return 0;
    }
    //cout<<f1<<" "<<f2<<endl;
    ll ans=0,c=-1;
    ll p1=0,p;
    for(ll i=0;i<s.size();i++)
    {
        if(s[i]=='<') c++;
        else if(c!=-1)
        {
            ans+=((c*(c+1))/2);
            c=-1;
        }
    }
    //cout<<ans<<endl;
    if(c!=-1)
    {
        c++;
        ans+=((c*(c+1))/2);
    }
    //cout<<ans<<endl;
    c=0;
    for(ll i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='>')
        {
            p=i; break;
        }
    }
    //cout<<p<<endl;
    vector<ll>a,b;
    for(ll i=p;i>=0;i--)
    {
        if(s[i]=='>') c++;
        else if(c!=0)
        {
            a.pb(c);
            c=0;
        }
        if(s[i]=='<') p1++;
        else if(p1!=0)
        {
            b.pb(p1);
            p1=0;
        }
    }
    if(c!=0)
    {
        a.pb(c);
        b.pb(0);
    }
    else b.pb(p1);
    //for(ll i=0;i<a.size();i++)
    //{
    //    cout<<a[i]<<" "<<b[i]<<endl;
    //}
    for(ll i=0;i<a.size();i++)
    {
        if(a[i]<b[i])
        {
            ll k=a[i]-1;
            ans+=((k*(k+1))/2);
            ans+=b[i];
        }
        else ans+=((a[i]*(a[i]+1))/2);
    }
    cout<<ans;
}