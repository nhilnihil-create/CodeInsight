#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[n-1],b[n-1];
    vector<vector<pair<int,int>>>pas(n);
    for(int i=0;i<n-1;i++){
        cin>>a[i]>>b[i];
        pas[a[i]-1].push_back({b[i]-1,i});
        pas[b[i]-1].push_back({a[i]-1,i});
    }
    int x=0;
    int color[n-1],check[n]={},used_c[n];
    used_c[0]=1000000;
    check[0]=1;
    queue<int>q;
    q.push(0);
    while(q.size()){
        int f=q.front();
        q.pop();
        int p=0;
        for(int i=0;i<pas[f].size();i++){
            if(check[pas[f][i].first]==0){
                q.push(pas[f][i].first);
                if(p==used_c[f])p++;
                color[pas[f][i].second]=p;
                used_c[pas[f][i].first]=p;
                p++;
                x=max(x,p);
                check[pas[f][i].first]=1;
            }
        }
    }
    cout<<x<<endl;
    for(int i=0;i<n-1;i++)cout<<color[i]+1<<endl;
    return 0;
}