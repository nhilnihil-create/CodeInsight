#include <iostream>
#include <set>
using namespace std;
#define ll long long 
#define vvll vector<vector<long long>>
#define vll vector<long long>
#define fri(i,n) for(int i=0;i<n;i++)
#define fri1(i,n) for(int i=n-1;i>=0;i--)
#define map map<ll,ll>
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ump unordered_map<long long ,long long>
#define ub upper_bound
#define bsearch binary_search

ll parent[100001]={0};

int find(int x)
{
    if(parent[x]!=x)
    {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

int main() 
{
    fast
    ll n,m,x,y;
    cin>>n>>m;
    fri(i,n+1)
    {
        parent[i]=i;
    }
    fri(i,m)
    {
        cin>>x>>y;
        if(find(y)!=find(x))
        {
        parent[find(y)]=find(x);
        }
    }
    set<int> st,st1;
    for(int i=1;i<=n;i++)
    {
        st.insert(parent[i]);
    }
    for(auto it: st)
    {
        st1.insert(find(it));
    }
    cout<<st1.size()-1<<"\n";
	return 0;
}
