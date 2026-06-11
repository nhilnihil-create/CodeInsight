#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC target("avx,avx2,fma,sse,sse2")
#pragma GCC optimization ("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;

#define N 200007

typedef tree<int, null_type, less<int>,rb_tree_tag,
tree_order_statistics_node_update> new_data;
int main()
{
    map<int,int>mp;
    int n,m,WA=0,AC=0;
    cin>>n>>m;
    int dp[n+5]={};
    set<int>ss;
    for(int i=0;i<m;i++)
    {
        string s;
        int x;
        cin>>x>>s;
        if(s=="WA")
        {
            if(mp[x]==0)dp[x]++;
        }
        else if(s=="AC")
        {
            if(mp[x]==0)AC++,mp[x]=1,ss.insert(x);
        }
    }
    for(auto i:ss)if(mp[i])WA+=dp[i];
        cout<<AC<<" "<<WA<<endl;

}
