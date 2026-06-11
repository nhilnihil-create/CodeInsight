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
    map<int,int>mm;
    int x;
    int tot=0;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        mm[x]++;
        tot^=x;
    }
    int sz=mm.size();
    if(sz>3)
    {
        cout<<"No";
    }
    else
    {
        vector<int>v;
        for(auto i:mm)
            v.push_back(i.second);
        int tt1=(n+2)/3;
        int tt2=(n+1)/3;
        int tt3=n/3;
        sort(v.begin(),v.end());
        if(v.back()>=tt1)
        {
            int z=v.back();
            v.pop_back();
            z-=tt1;
            if(z>0)
                v.push_back(z);
            sort(v.begin(),v.end());

            if(v.back()>=tt2)
            {
                int z=v.back();
                v.pop_back();
                z-=tt2;
                if(z>0)
                    v.push_back(z);
                sort(v.begin(),v.end());                
                if(v.back()>=tt3)
                {
                    if(tot==0)
                        cout<<"Yes";
                    else
                        cout<<"No";
                }
                else
                    cout<<"No";
            }
            else
            {
                cout<<"No";
            }
        }
        else
        {
            cout<<"No";
        }
    }
} 
