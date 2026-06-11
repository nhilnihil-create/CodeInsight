#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define PB push_back
const int N=1e4+10;
int main(){
    int n,m,l,r,d[N],nxt;
    queue<int> q;
    vector<int> graph[N];
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)d[i]=0;
    while(m--){
        scanf("%d%d",&l,&r);
        graph[l].PB(r);
        d[r]++;
    }
    for(int i=0;i<n;i++)if(d[i]==0)q.push(i);
    while(!q.empty()){
        nxt=q.front();
        q.pop();
        printf("%d\n",nxt);
        for(int i=0;i<graph[nxt].size();i++){
            d[graph[nxt][i]]--;
            if(d[graph[nxt][i]]==0)q.push(graph[nxt][i]);
        }
    }
}
