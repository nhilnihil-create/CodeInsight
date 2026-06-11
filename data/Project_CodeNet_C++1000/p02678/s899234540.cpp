#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,nodes,edges;
    cin>>nodes>>edges;
    nodes++;
    vector <int> v[nodes];
    for(int i=0;i<edges;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    int s=1,vis[nodes]={0},level[nodes]={0};
    queue <int> q;
    q.push(s);
    level[1]=0;
    vis[1]=1;
    while(!q.empty()){
        int p=q.front();
        q.pop();
            for(int i=0;i<v[p].size();i++){
                if(vis[ v[p][i] ] == 0){
                        level[ v[p][i] ]=p;
                        vis[ v[p][i] ]=1;
                        q.push(v[p][i]);
                }
            }
    }
    int k=0;
    for(int i=2;i<nodes;i++){
        if(level[i]==0){
            k=-1;
            break;
        }

    }
    if(k==-1)
        cout<<"No"<<endl;
    else{
        cout<<"Yes"<<endl;
        for(int i=2;i<nodes;i++)
                cout<<level[i]<<endl;
    }

}
