#include<bits/stdc++.h>
#define PI 3.141592653589793238462
using namespace std;
typedef long long ll;
typedef long double db;
int pre[100005];
int find(int x){
    return (x==pre[x])?x:(pre[x]=find(pre[x]));
}
void merge(int x,int y){
    pre[find(x)]=find(y);
}
int main(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        pre[i]=i;
    }
    for(int i=1;i<=m;i++){
        int u,v;cin>>u>>v;
        merge(u,v);
    }
    set<int> s;
    for(int i=1;i<=n;i++){
        s.insert(find(i));
    }
    cout<<s.size()-1<<endl;
} 