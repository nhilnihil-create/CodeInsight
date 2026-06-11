#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
using namespace std;
#define N (1000000000+7)
#define M (998244353)
#define INF 1e16
typedef long long ll;
typedef pair<int,int> P;

vector<int>g[100010];
set<int>color[100010];
bool visited[100010];

int main(void){
    int n;
    cin>>n;
    map<P,int>edge;
    vector<int>a(n),b(n);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        a[i]=x;
        b[i]=y;
        edge[P(x,y)]=0;
        edge[P(y,x)]=0;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    queue<int>que;
    que.push(1);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        visited[now]=true;
        int c =1;
        for(int i=0;i<g[now].size();i++){
            int next = g[now][i];
            if(visited[next])continue;
            if(color[now].count(c)==0){
                color[now].insert(c);
                color[next].insert(c);
                edge[P(now,next)]=c;
                edge[P(next,now)]=c;
                c++;
                que.push(next);
            }
            else{
                c++;
                color[now].insert(c);
                color[next].insert(c);
                edge[P(now,next)]=c;
                edge[P(next,now)]=c;
                c++;
                que.push(next);
            }
        }
    }
    set<int>s;
    for(int i=0;i<n-1;i++){
        s.insert(edge[P(a[i],b[i])]);
    }
    cout<<s.size()<<endl;
    for(int i=0;i<n-1;i++){
        cout<<edge[P(a[i],b[i])]<<endl;
    }
    return 0;
}