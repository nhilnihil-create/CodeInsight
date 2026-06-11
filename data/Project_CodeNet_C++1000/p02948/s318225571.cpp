#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> job(m+1);
    for(int i=0;i<n;++i){
        int a,b;
        cin>>a>>b;
        if(a>m) continue;
        job[a].push_back(b);
    }

    priority_queue<int> pq;
    int res=0;
    for(int i=0;i<=m;++i){
        for(auto v:job[i]) pq.push(v);
        if(pq.empty()) continue;
        res+=pq.top();
        pq.pop();
    }
    
    cout<<res<<endl;
}