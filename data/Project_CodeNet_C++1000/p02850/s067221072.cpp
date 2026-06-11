#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
struct Edge{
    int to;
    int id;
};

vector<Edge> g[100005];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        g[a].push_back(Edge{b,i});
        g[b].push_back(Edge{a,i});
    }
    queue<int> q;
    q.push(0);
    vector<int> color(n,-1);
    vector<int> pre(n+1,-1);
    while(!q.empty()){
        int c=q.front();q.pop();
        int tempc=1;
        for(Edge item:g[c]){
            if(color[item.id]>0) continue;
            if(tempc==pre[c]) tempc++;
            pre[item.to]=tempc;
            color[item.id]=tempc;
            tempc++;
            q.push(item.to);
        }
    }
    cout<<*max_element(color.begin(),color.end())<<endl;
    for(int i=0;i<n-1;i++){
        cout<<color[i]<<endl;
    }
    return 0;
}