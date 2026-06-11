#include<bits/stdc++.h>
//pbds
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>   using orderedSet =tree<T, null_type, less<T>,rb_tree_tag, tree_order_statistics_node_update>;
///use less_equal in pbds template to work as multiset...................................................
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define pb push_back
//BFS+DFS
#define boundary(i,j) (i>=0 && i<n && j>=0 && j<m)
int X[]={-1,1,0,0};
int Y[]={0,0,1,-1};
int cnt1[300005],cnt2[300005];
vector<int>v1,v2;
vector<int>r,c;
set<pii>mp;
int main()
{
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     int h,w,m;
     cin>>h>>w>>m;
     int mx1=0,mx2=0;
     for(int i=0; i<m; i++)
     {
         int x,y;
         cin>>x>>y;
         mp.insert({x,y});
         ++cnt1[x];
         ++cnt2[y];
         mx1=max(mx1,cnt1[x]);
         mx2=max(mx2,cnt2[y]);
     }

    for(int i=1; i<=h; i++)
        {
            if(cnt1[i]==mx1) r.pb(i);
        }
           for(int i=1; i<=w; i++)
        {
            if(cnt2[i]==mx2) c.pb(i);
        }
        int ans=mx1+mx2-1;
     for(int i:r)
     {
         for(int j:c)
         {

             if(mp.find({i,j})==mp.end())
                {
                    ans=mx1+mx2;
                    break;
                }


         }
         if(ans==mx1+mx2) break;
     }
     cout<<ans<<endl;


}


