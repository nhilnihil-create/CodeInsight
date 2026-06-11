#include<iostream>
using namespace std;
#define ll long long
#include<vector>
#include<set>
//vector<ll>adj[100001];
ll parent[100001];
ll tao[100001];
ll find(ll i) {
    if(parent[i]==i)
        return i;
    else
        return parent[i]=find(parent[i]);
}
void union_set(ll a,ll b) {
    ll x=find(a);
    ll y=find(b);
    if(tao[x]<tao[y])swap(x,y);
    parent[y]=x;
    if(tao[x]==tao[y])tao[x]++;

}
set<ll>s;
int main()
{
    ll n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++) {
        parent[i]=i;
        tao[i]=1;
    }
    while(m--) {
        ll l,r;
        cin>>l>>r;
        union_set(l,r);
    }
    for(int i=1; i<=n; i++)
        s.insert(find(i));
    cout<<s.size()-1<<endl;

    return 0;
}