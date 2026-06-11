#include<bits/stdc++.h>
using namespace std;
#define lint long long
#define inf 100000000000000000
#define mod 1000000007
#define MAX 200005
#define pb push_back
#define mp make_pair
#define vit vector<int>::iterator
typedef pair<lint,lint> pii;
struct DSU{ /// O(1) approximately. Worst case O(log(n)) for 1 find.
    vector<lint>parent,rank;
    DSU(lint n){
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=1;i<=n;i++){
            make_set(i);
        }
    }
    void make_set(lint v){
        parent[v]=v;
        rank[v]=0;
    }
    lint find_set(lint v){
        if(parent[v]==v) return v;
        return parent[v]=find_set(parent[v]); // path compression
    }
    bool union_set(lint u,lint v){
        u=find_set(u);
        v=find_set(v);
        if(u!=v){
            if(rank[u]<rank[v]) swap(u,v);
            parent[v]=u;
            if(rank[u]==rank[v]) rank[u]++; // union by rank
            return true;
        }
        else return false;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    lint n,m,u,v,w;
    cin>>n>>m;
    DSU ds(n);
    while(m--){
        cin>>w>>u>>v;
        if(!w) ds.union_set(u+1,v+1);
        else{
            if(ds.find_set(u+1)==ds.find_set(v+1)) cout<<"1\n";
            else cout<<"0\n";
        }
    }

    return 0;
}

