#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    vector<vector<int>>pas(n);
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        pas[a[i]-1].push_back(b[i]-1);
    }
    int s,t;
    cin>>s>>t;
    s--;
    t--;
    queue<pair<int,int>>q;
    q.push({s,0});
    int check[n][3]={};
    check[s][0]=1;
    while(q.size()){
        int f=q.front().first,d=q.front().second;
        q.pop();
        if(f==t && d%3==0){
            cout<<d/3<<endl;
            return 0;
        }
        for(int i=0;i<pas[f].size();i++){
            if(check[pas[f][i]][(d+1)%3]==0){
                check[pas[f][i]][(d+1)%3]=1;
                q.push({pas[f][i],d+1});
            }
        }
    }
    cout<<"-1"<<endl;
    return 0;
}