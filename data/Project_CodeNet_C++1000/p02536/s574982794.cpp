#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const int maxn=1e5+5;
const ll inf=1e18;
int N,M;
int fa[maxn];
int find(int x){
    if(fa[x]!=x)fa[x]=find(fa[x]);
    return fa[x];
}
int main(){
    cin>>N>>M;
    for(int i=1;i<=N;i++)fa[i]=i;

    for(int i=1;i<=M;i++){
        int a,b;
        cin>>a>>b;
        int faa=find(a);
        int fab=find(b);
        if(faa!=fab)
        fa[faa]=fab;
    }
    int cnt=-1;

    for(int i=1;i<=N;i++){
        find(i);
        if(fa[i]==i)cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}
