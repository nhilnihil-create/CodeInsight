#include <iostream>

using namespace std;
const int N=1e5+10;
int p[N];
int ans;
int find(int u){
    return p[u]==u?p[u]:p[u]=find(p[u]);
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)p[i]=i;
    for(int i=1;i<=m;++i){
        int a,b;
        cin>>a>>b;
        a=find(a),b=find(b);
        if(a!=b)p[a]=b;
    }
    for(int i=1;i<=n;++i){
        if(i==p[i])ans++;
    }
    cout<<ans-1<<endl;
}