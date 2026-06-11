#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
using namespace std;
const int inf=1e+6;
//ダイクストラ法の計算量はO(NlogV)だぞ！！ O(NV)じゃないんだぞ！！
int main(void){
    int n,m;cin>>n>>m;
    vector<vector<int>> t(n);
    rep(i,m){
        int u,v;cin>>u>>v;u--,v--;
        t[u].push_back(v);
    }
    int s,T;cin>>s>>T;s--;T--;
    vector<vector<ll>> p(n,vector<ll>(3,inf));
    queue<pair<int,int>> que;
    que.push({s,0});
    p[s][0]=0;//3で割った余り どれにもなれるなら3を入れる
    while(que.size()){
        int x=que.front().first,now=que.front().second; que.pop();
        ll y=p[x][now];
        rep(i,t[x].size()){
            int z=t[x][i];
            if(p[z][(now+1)%3]!=inf)continue;
            p[z][(now+1)%3]=y+1;
            que.push({z,(now+1)%3});
        }
    }
    ll dis=p[T][0];
    if(dis==inf){
        cout<<-1<<endl;
        return 0;
    }else{
        ll res=(dis+2)/3;
        cout<<res<<endl;
        return 0;
    }
}
