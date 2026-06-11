#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,a,b) for(int i=a;i<b+1;i++)
#define Per(i,b,a) for(int i=b;i>=a;i--)

int main(){
    int N,M;
    cin>>N>>M;
    int v,u;
    vector<int> edge[300000];
    rep(i,M){
        cin>>u>>v;
        v--;u--;
        edge[3*u].push_back(3*v+1);
        edge[3*u+1].push_back(3*v+2);
        edge[3*u+2].push_back(3*v);
    }
    int S,T;
    cin>>S>>T;
    S--;T--;
    S*=3;T*=3;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push(make_pair(0,S));
    bool done[300000];
    rep(i,3*N) done[i] = false;
    while(1){
        if(q.empty()) break;
        pair<int,int> p = q.top();
        q.pop();
        if(done[p.second]) continue;
        if(p.second == T){
            cout<<p.first/3<<endl;
            return 0;
        }
        done[p.second] = true;
        rep(i,edge[p.second].size()){
            if(done[edge[p.second][i]]) continue;
            q.push(make_pair(p.first+1,edge[p.second][i]));
        }
    }
    cout<<-1<<endl;
    return 0;
}