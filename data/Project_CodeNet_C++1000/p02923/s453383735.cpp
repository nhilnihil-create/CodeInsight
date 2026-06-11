/*
  AUTHOR:SOURABH
  CREATED:02:09:20
*/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define ordered_set tree<ll , null_type, less< ll >, rb_tree_tag, tree_order_statistics_node_update>
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
#define pob pop_back
#define W while
#define fn(i,x) for(i=0;i<x;i++)
#define fs(i,s,x) for(i=s;i<x;i++)
#define fr(i,x) for(i=x;i>=0;i--)
#define fit(it,s) for(it=s.begin();it!=s.end();it++)
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<int>
#define vll vector<ll>
#define mii map<int,int>
#define mll map<ll,ll>
#define mod 1000000007
#define MAXN 10000001
#define M 32

using namespace std;
using namespace __gnu_pbds;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //freopen("input.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    ll t,n,i,curr,ans;
    t=1;
    //cin>>t;
    W(t--)
    {
        cin>>n;
        vll a(n);
        fn(i,n)
        cin>>a[i];
        ans=0;curr=0;
        fn(i,n-1)
        {
            if(a[i]>=a[i+1])
            {curr++;ans=max(ans,curr);}
            else
            curr=0;
        }
        cout<<ans;
    }
    return 0;
}

