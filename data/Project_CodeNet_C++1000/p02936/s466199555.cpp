#include <bits/stdc++.h>
using namespace std;

int main(){
    long n,q;cin>>n>>q;
    vector<vector<long>> graph(n+1);
    for(int i=1;i<n;i++){
        long a,b;cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<long> score(n+1,0);
    vector<long> scoredp(n+1,0);
    for(long i=0;i<q;i++){
        long p,x;cin>>p>>x;
        scoredp[p]+=x;
    }
    stack<long> s;s.push(1);
    vector<long> prev(n+1,0);
    while(s.size()!=0){
        long a=s.top();
        s.pop();
        score[a]+=scoredp[a];
        prev[a]=1;
        for(int i=0;i<graph[a].size();i++){
            if(prev[graph[a][i]]==0){
                score[graph[a][i]]+=score[a];
                s.push(graph[a][i]);
            }
        }
    }
    for(long i=1;i<n;i++)cout<<score[i]<<" ";
    cout<<score[n]<<endl;
}