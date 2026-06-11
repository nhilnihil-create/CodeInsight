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
    int a[n+1];
    vector<int>x,y;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<0)
            x.push_back(a[i]);
        else
            y.push_back(a[i]);
    }
    sort(a,a+n+1);
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    vector<pair<int,int> >ans;
    int sz1=x.size();
    int sz2=y.size();
    int res=0;
    if(sz1&&sz2)
    {
        int tt=x[0];
        for(int i=0;i<sz2-1;i++)
        {
            ans.push_back({tt,y[i]});
            tt-=y[i];
        }
        int ff=y[sz2-1];
        for(int i=1;i<sz1;i++)
        {
            ans.push_back({ff,x[i]});
            ff-=x[i];
        }
        ans.push_back({ff,tt});
        res=ff-tt;
    }
    else if(sz1)
    {
        int tt=x[0];
        ans.push_back({x[sz1-1],tt});
        tt=x[sz1-1]-tt;
        for(int i=1;i<sz1-1;i++)
        {
            ans.push_back({tt,x[i]});
            tt-=x[i];
        }
        res=tt;
    }
    else if(sz2==2)
    {
        ans.push_back({y[1],y[0]});
        res=y[1]-y[0];
    }
    else
    {
        int tt=y[0];
        ans.push_back({tt,y[sz2-1]});
        tt-=y[sz2-1];
        for(int i=1;i<sz2-2;i++)
        {
            ans.push_back({tt,y[i]});
            tt-=y[i];
        }
        ans.push_back({y[sz2-2],tt});
        tt=y[sz2-2]-tt;
        res=tt;
    }
    cout<<res<<'\n';
    for(auto i:ans)
        cout<<i.first<<" "<<i.second<<"\n";

} 

