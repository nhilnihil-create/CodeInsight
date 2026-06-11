#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
ll k;
int niz[200005];
int dist[200005];

int bfs(int start){
    memset(dist,-1,sizeof(dist));
    dist[start]=0;
    queue<int>q;
    q.push(start);
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        int next=niz[cur-1];
        if(dist[next]==-1){
            dist[next]=dist[cur]+1;
            q.push(next);
        }else{
            int cycle=dist[cur]+1-dist[next];
            int target;
            if(k<dist[next]){
                target=k;
            }else{
                target=(k-dist[next])%cycle +dist[next];
            }
            for(int i=1;i<=n;i++)
                if(dist[i]==target)
                    return i;
        }
    }
}

int main(){
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>niz[i];
    cout <<bfs(1);
}
