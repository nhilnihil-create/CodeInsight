#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;

    vector<vector<int>> c(M+1);
    int a,b;
    for(int i=0;i<N;i++){
        cin>>a>>b;
        if(a<=M){
            c[a].emplace_back(b);
        }
    }

    int ans=0;
    priority_queue<int> q;
    for(int i=1;i<=M;i++){
        for(auto p:c[i]){
            q.push(p);
        }
        if(!q.empty()){
            ans+=q.top();
            q.pop();
        }
    }
    cout<<ans<<endl;
    
    return 0;
}