#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> m;
vector<int> g[100005];
int c[100005];
int N;
void dfs(int now,int pre,int num){
    if(num==N-1)return;
    else{
        int K=0;
        int count=num;
        for(int u:g[now]){
            if(u!=pre){
                K++;
                if(c[m[make_pair(min(pre,now),max(pre,now))]]==K)K++;
                if(c[m[make_pair(min(u,now),max(u,now))]]==0){
                    c[m[make_pair(min(u,now),max(u,now))]]=K;
                    count++;
                }
            }
        }
        for(int u:g[now]){
            if(u!=pre)dfs(u,now,count);
        }
    }}


int main(){
    int a,b;
    cin >> N;
    for(int i=1;i<N;i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        m[make_pair(a,b)]=i;
    }
    dfs(1,-1,0);
    int ans=0;
    for(int i=1;i<N;i++)ans=max(ans,c[i]);
    cout << ans << endl;
    for(int i=1;i<N;i++)cout << c[i] << endl;
}