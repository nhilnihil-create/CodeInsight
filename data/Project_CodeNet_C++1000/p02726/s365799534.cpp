#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    int n,x,y;
    cin >> n >> x >> y;
    x--;    y--;
    
    vector<int> ans(n+1);
    for(int i=0;i<n;i++){
        queue<int> q;
        vector<int> dist(n,-1);
        dist[i] = 0;
        q.push(i);

        while(!q.empty()){
            int now = q.front();
            q.pop();

            if(now!=0 && dist[now-1]==-1){
                dist[now-1] = dist[now]+1;
                q.push(now-1);
            }
            if(now!=n-1 && dist[now+1]==-1){
                dist[now+1] = dist[now]+1;
                q.push(now+1);
            }
            if(now==x||now==y){
                int next = x+y-now;
                if(dist[next]==-1){
                    dist[next] = dist[now]+1;
                    q.push(next);
                }
            }
        }

        for(int j=0;j<n;j++) ans[dist[j]]++;
    }

    for(int i=1;i<n;i++) cout << ans[i]/2 << endl;
    return 0;
}