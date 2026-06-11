#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define pi 3.141592653589793238
#define int long long
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



signed main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   

#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif  

    int n;
    cin>>n;
    pair<int,int>p[n+1];
    vector<pair<int,int> >pp;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;        
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            pp.push_back({p[j].first-p[i].first,p[j].second-p[i].second});
        }
    }
    int mn=1e10;
    sort(p+1,p+n+1);
    for(auto i:pp)
    {
        int mm[n+1]={0};
        int ans=0;
        int cnt=n;
        while (cnt)
        {
            pair<int,int>prev={-1e10,-1e10};
            for(int j=1;j<=n;j++)
            {
                if(mm[j]==0)
                {
                        ans++;
                        cnt--;
                        prev=p[j];
                        mm[j]=1;
                        break;
                }
            }
            for(int j=1;j<=n;j++)
            {
                if(mm[j]==0)
                {
                    if(p[j].first-prev.first==i.first && p[j].second-prev.second==i.second)
                    {
                        cnt--;
                        mm[j]=1;
                        prev=p[j];
                    }
                }
            }     
        }
        mn=min(mn,ans);
        
    }
    cout<<mn;

} 

