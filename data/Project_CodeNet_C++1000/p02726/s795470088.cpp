#include<iostream>
#include<queue>
#include<queue>
using namespace std;

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    x--;
    y--;
    vector<int> ans(n);

    for(int i=0;i<n;i++){
        vector<int> d(n,1e9);
        queue<int> q;
        auto push=[&](int v,int r){
            if(d[v]!=1e9) return;
            d[v]=r;
            q.push(v);
        };
        push(i,0);
        while(!q.empty()){
            int v=q.front();
            q.pop();
            if(v-1>=0) push(v-1,d[v]+1);
            if(v+1<n) push(v+1,d[v]+1);
            if(v==x) push(y,d[v]+1);
            if(v==y) push(x,d[v]+1);
        }
        for(int t : d) ans[t]++;
    }
    for(int i=1;i<n;i++) cout<<ans[i]/2<<endl;
}