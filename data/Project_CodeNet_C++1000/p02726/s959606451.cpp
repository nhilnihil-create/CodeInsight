#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<queue>
#include<cmath>
#define REP(i,a) for (int i = 0;i < (a);++i)
#define FOR(i,a,b) for (int i = (a);i < (b); ++i)
#define FORR(i,a,b) for (int i = (a);i >= (b); --i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SORT(list) sort(ALL((list)));
#define MOD 1000000007
using namespace std;
using ll = long long;
int main(){
    int n,x,y;
    cin >> n >> x >> y;
    vector<vector<int> > Graph(n);
    queue<int>que;
    vector<int>dist(n,0);
    vector<int>answer(n,0);
    REP(i,n-1){
        Graph[i].push_back(i+1);
        Graph[i+1].push_back(i);
    }
    x--;
    y--;
    Graph[x].push_back(y);
    Graph[y].push_back(x);
    REP(i,n){
        que.push(i);
        REP(j,n)dist[j]=-1;
        dist[i]=0;
        while(!que.empty()){
            int v = que.front();
            que.pop();

            for(int nv:Graph[v]){
                if(dist[nv]!=-1)
                    continue;
                dist[nv] = dist[v]+1;
                que.push(nv);
            }
        }
        REP(j,n)answer[dist[j]]++;
    }
    FOR(i,1,n)cout << answer[i]/2 << endl;
    return 0;
}