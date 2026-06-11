/* /\ In The Name of ALLAH /\
    Author : Jawahiir Nabhan */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MX = 2e5 + 10;

int vis[MX],p[MX],res;
void init(int n){
    for(int i=0;i<=n;i++) p[i] = i,vis[i] = 1;
}
int findnemo(int r){
    if(p[r] == r) return r;
    return p[r] = findnemo(p[r]);
}
void unite(int u,int v){
    int x = findnemo(u);
    int y = findnemo(v);
    if(x != y){
        p[y] = x;
        vis[x] += vis[y];
    }
}
int main()
{
    int n,m; cin>>n>>m;
    res = 0;
    init(n);
    for(int i = 0;i < m;i++)
    {
        int x,y; cin>>x>>y;
        unite(x , y);
    }
    cout<<*max_element(vis + 1, vis + 1 + n)<<endl;
}
