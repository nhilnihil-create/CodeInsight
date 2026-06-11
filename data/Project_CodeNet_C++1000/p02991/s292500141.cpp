#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<int, int>
using namespace std;

int main(){
    int n,m; cin >> n >> m;
    vector<vector<int> > ki(n*3);
    vector<int> visit(n*3,0);
    rep(i,m){
        int u,v; cin >> u >> v;
        u--; v--;
        rep(j,3) ki[3*u+j].push_back(3*v+((j+1)%3));
    }
    int s,t; cin >> s >> t;
    s--; t--;
    s*=3; t*=3;

    queue<P> p;
    p.push(P(s,0));
    int ans=-1;
    while(!p.empty()){
        int now=p.front().first;
        int num=p.front().second;
        p.pop();
        if(visit[now]) continue;
        if(now==t){
            ans=num;
            break;
        }
        visit[now]++;
        rep(i,ki[now].size()) p.push(P(ki[now][i],num+1));
    }
    if(ans!=-1) ans/=3;
    cout << ans << endl;
return 0;
}