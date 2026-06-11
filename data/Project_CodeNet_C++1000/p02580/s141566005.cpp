#include<bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#define sint int32_t
#define int long long int
#define all(v) v.begin() , v.end()
#define vii vector<int>
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int32_t main()
{   fastio;

    int x , y , p;
    cin>>x>>y>>p;
    unordered_map<int , int>r;
    unordered_map<int , int>h;
    vector<pii>v;
    map<pii , int>mp;
    for(int i=0; i<p; i++) {
        pii p ;
        cin>>p.first>>p.second;
        r[p.F]++;
        h[p.S]++;
        mp[p]++;
    }
    int m , n;
    int fm=0 , fn=0;
    for(auto x:r) {
        if(x.S>fm) {
            fm = x.S;
            m = x.F;
        }
    }

    int cnt = fm ;

    for(int i=1; i <= (sint)3e5; i++)
    {
        if(h.count(i))
        {
            if(mp.count({m , i})) {
                cnt = max(cnt , fm-1+h[i]);
            }
            else cnt = max(cnt , fm + h[i]);
        }
    }
    for(auto x:h) {
        if(x.S>fn) {
            fn = x.S;
            n = x.F;
        }
    }

    int ont = fn ;

    for(int i=1; i <= (sint)3e5; i++)
    {
        if(r.count(i))
        {
            if(mp.count({i , n})) {
                ont = max(ont , fn-1+r[i]);
            }
            else ont = max(ont , fn + r[i]);
        }
    }
    cout<<max(cnt , ont)<<"\n";



}

