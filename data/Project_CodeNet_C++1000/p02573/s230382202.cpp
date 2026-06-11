#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> d(n);
    vector<int> list(n);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        a--;b--;
        d[a].push_back(b);
        d[b].push_back(a);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        //if(list[i]==1)continue;
        queue<int> q;
        q.push(i);
        list[i]=1;
        int sum=1;
        while(!q.empty()){
            int p=q.front();
            q.pop();
            for(auto np:d[p]){
                if(list[np]==1)continue;
                list[np]=1;
                q.push(np);
                sum+=1;
            }
        }
        ans=max(ans,sum);
    }
    cout <<ans;
}