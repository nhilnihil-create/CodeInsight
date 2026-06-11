#include<bits/stdc++.h>
using namespace std; 
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,m;
    cin>>n>>m;
    vector<int>wa(n,0);
    vector<bool>c(n,false);
    for(int i=0;i<m;i++)
    {
        string s;
        ll x;
        cin>>x>>s;
        x--;
        if(s=="AC")
            c[x]=true;
        if(s=="WA"&&c[x]==false)
            wa[x]++;
    }
    ll c1=0,p1=0;
    for(int i=0;i<n;i++)
    {
        if(c[i])
        {
            c1++;
            p1+=wa[i];
        }
    }
    cout<<c1<<" "<<p1<<endl;
    return 0;
}
