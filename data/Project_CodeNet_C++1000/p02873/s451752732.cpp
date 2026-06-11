#include <bits/stdc++.h>
using namespace std;

using str = string;
using ll = long long;

int a[500010];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    str s;
    cin>>s;
    
    int n=s.size()+1;
    
    int nn=0;
    int sn=0;
    int mn=0;
    
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='<')nn++;
        else nn--;
        sn=min(sn,nn);
        mn=min(mn,nn);
        a[i+1]=nn;
    }
    
    vector<pair<int,int>> p;
    bool down=true;
    sn=0;
    
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        {
            sn=min(sn,a[i]);
            p.push_back(make_pair(n-1,sn));
        }
        else
        {
            if(down&&a[i-1]<a[i])
            {
                down=false;
            }
            else if(!down&&a[i-1]>a[i])
            {
                p.push_back(make_pair(i-1,sn));
                sn=a[i];
                down=true;
            }
            else 
            {
                sn=min(sn,a[i]);
            }
        }
    }
    
    int cur=0;
    
    for(int i=0;i<n-1;i++)
    {
        if(p[cur].first<i)cur++;
        if(p[cur].first==i)
        {
            a[i]-=min(p[cur].second,p[cur+1].second);
        }
        else a[i]-=p[cur].second;
    }
    
    a[n-1]-=p[cur].second;
    
    ll ans=0;
    for(int i=0;i<n;i++)ans+=a[i];
    
    cout<<ans<<"\n";
    
    return 0;
}

