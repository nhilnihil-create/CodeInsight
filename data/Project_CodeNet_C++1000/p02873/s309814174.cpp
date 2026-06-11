#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    ll a[500005]={};
    ll b[500005]={};
    ll ans=0;
    cin>>s;
    for(int i=1;i<=s.size();i++)
    {
        if(s[i-1]=='<')
            a[i]=a[i-1]+1;
    }
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='>')
            b[i]=b[i+1]+1;
    }
    for(int i=0;i<=s.size();i++)
        ans+=max(a[i],b[i]);
    cout<<ans<<endl;
    return 0;
}