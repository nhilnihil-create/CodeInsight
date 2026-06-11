#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define deb(x) cerr << #x << ":" << x << "\n"
#define all(x) x.begin(),x.end()

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

#define int ll

void solve()
{
    int n;
    cin>>n;
    vector<multiset<int>> v(4);
    for(int i=0;i<4;i++)v[i]=multiset<int>();
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[0].insert(x+y);
        v[1].insert(x-y);
        v[2].insert(-x+y);
        v[3].insert(-x-y);
    }
    if(n==1){
        cout<<"0\n";
        return;
    }
    int ans=*(v[0].rbegin());
    v[0].erase(prev(v[0].end()));
    ans-=*(v[0].begin());
    ans=max(ans,(*(v[1].rbegin()))-(*(v[1].begin())));
    ans=max(ans,(*(v[3].rbegin()))-(*(v[3].begin())));
    ans=max(ans,(*(v[2].rbegin()))-(*(v[2].begin())));
    cout<<ans<<"\n";
}

int32_t main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}