#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,q,poz[200001];
vector<int> v[200001];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=0;i<=n;i++)
    {
        poz[i]=i;
        v[i].push_back(i);
    }
    while(q--)
    {
        int tip,a,b;
        cin>>tip>>a>>b;
        if(tip==0)
        {
            int m1=poz[a];
            int m2=poz[b];
            if(m1==m2)
                continue;
            if(v[m1].size()>v[m2].size())
                swap(m1,m2);
            for(auto i:v[m1])
            {
                v[m2].push_back(i);
                poz[i]=m2;
            }
            v[m1].clear();
        }
        else if(tip==1)
            cout<<(poz[a]==poz[b]? 1:0)<<'\n';
    }
    return 0;
}
