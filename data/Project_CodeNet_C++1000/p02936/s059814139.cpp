#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> Graph;
typedef vector<ll> vll;

template <class type> void printVector(vector<type> vec){
    stringstream ss;
    ll n = vec.size();
    for(ll i=0;i<n;i++)
    {
        ss<<vec[i];
        if(i!=n-1)ss<<" ";
    }
    cout<<ss.str()<<endl;
}


void dfs(Graph& tree,vll& cnt,ll parent,ll i)
{
    for(auto child:tree[i])//子全てに対して行う
    {
        if(child==parent)continue;//親に対しては足し算しない
        cnt[child]+=cnt[i];
        dfs(tree,cnt,i,child);
    }
}

int main(){
    ll N,Q;
    cin>>N>>Q;
    Graph tree(N);
    vll cnt(N,0);
    for(ll i=0;i<N-1;i++)
    {
        ll a,b;cin>>a>>b;--a;--b;
        tree[a].emplace_back(b);
        tree[b].emplace_back(a);
    }

    for(ll i=0;i<Q;i++)
    {
        ll p,x;cin>>p>>x;--p;
        cnt[p]+=x;
    }

    dfs(tree,cnt,-1,0);
    printVector(cnt);
}