#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
typedef long long ll;
int n,m,q,ret,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
void dfs(vector<int> v){
    if(v.size()==n){
        int score=0;
        // for(int i=0;i<v.size();++i)cout<<v[i]<<' ';cout<<endl;
        for(int i=0;i<q;++i)if(v[b[i]-1]-v[a[i]-1]==c[i])score+=d[i];
        // cout<<score<<endl;
        ret=max(ret,score);
        return;
    }
    int back=v[v.size()-1];
    v.push_back(-1);
    for(int i=back;i<=m;++i){v.pop_back();v.push_back(i);dfs(v);}
}
int main(){
    cin>>n>>m>>q;
    for(int i=0;i<q;++i)cin>>a[i]>>b[i]>>c[i]>>d[i];
    vector<int> v;v.push_back(-1);
    for(int i=1;i<=m;++i){v.pop_back();v.push_back(i);dfs(v);}
    cout<<ret<<endl;
    return 0;
}
