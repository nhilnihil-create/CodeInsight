#include <bits/stdc++.h>
 
using namespace std;
 
map<int, int> ds;
map<int, int> ranks;
 
int find_root(int x) {
    return x==ds[x]?x:ds[x]=find_root(ds[x]);
}
 
void union_set(int x, int y) {
    int x_root=find_root(x);
    int y_root=find_root(y);
    if (x_root!=y_root) {
        if (ranks[x_root]>ranks[y_root]) {
            ds[y_root]=x_root; 
        } else if (ranks[x_root]<ranks[y_root]) {
            ds[x_root]=y_root;
        } else {
            ds[x_root]=y_root;
            ranks[y_root]++;
        }
    }
}
 
int main() {
    int n,m;
    cin>>n>>m;
 
    //初始化
    for (int i=1; i<=n; i++) {
        ds[i]=i;
        ranks[i]=0;
    }
 
    int cnt=0;
    for (int i=1; i<=m; i++) {
        int x,y;
        cin>>x>>y;
 
        x=find_root(x);
        y=find_root(y);
        if (x==y) {
            continue;
        }
 
        union_set(x, y);
        cnt++;
    }
 
    cnt=n-1-cnt;
    if (cnt<0) {
        cnt=0;
    }
    cout<<cnt<<"\n";
 
    return 0;
}