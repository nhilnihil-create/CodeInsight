#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n],b[n];
    vector<pair<int,int>>p(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        p[i]={a[i],b[i]};
    }
    sort(p.begin(),p.end());
    int rew=0,x=-1;
    priority_queue<int>q;
    for(int i=1;i<=m;i++){
        for(int j=x+1;p[j].first==i;j++){
            q.push(p[j].second);
            x=j;
        }
        if(q.size()){
            rew+=q.top();
            q.pop();
        }
    }
    cout<<rew<<endl;
    return 0;
}
