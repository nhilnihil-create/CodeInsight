#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main(){
    long N,M,u,v,S,T;
    cin>>N>>M;
    vector<long>g[3*N],d(3*N);
    for(long i=0;i<M;i++){
        cin>>u>>v;
        u--,v--;
        g[3*u+0].push_back(3*v+1);
        g[3*u+1].push_back(3*v+2);
        g[3*u+2].push_back(3*v+0);
    }
    cin>>S>>T;
    S--,T--;
    for(long i=0;i<3*N;i++)d[i]=100000000000000L;
    d[0]=0L;
    queue<pair<long,long>>q;
    q.push(make_pair(3*S,0L));
    while(!q.empty()){
        auto c=q.front();q.pop();
        if(c.first==3L*T){cout<<c.second/3L<<endl;return 0;}
        for(auto x:g[c.first])if(d[x]==100000000000000L)d[x]=c.second+1L,q.push(make_pair(x,c.second+1L));
    }
    cout<<-1<<endl;
    return 0;
}