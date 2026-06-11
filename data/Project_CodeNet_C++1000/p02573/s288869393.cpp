#include<bits/stdc++.h>
using namespace std;
const int MX=2e5+5;
int n,m,x,y,mx,a[MX];
int root(int i){
    return a[i]<0 ? i : (a[i]=root(a[i]));
}
void join(int x,int y){
    x=root(x),y=root(y);
    if(x==y) return;
    if(a[x]>a[y]) swap(x,y);
    a[x]+=a[y];
    a[y]=x; 
}
int main()
{
    cin >> n >> m;
    for(int i=0; i<=n; i++) a[i]=-1;
    for(int i=0; i<m; i++){
        cin >> x >> y;
        join(x,y);
    }
    for(int i=1; i<=n; i++){
        if(a[i]<0) mx=max(mx,-a[i]);
    }
    cout << mx;
    return 0;
}