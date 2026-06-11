#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    priority_queue<int,vector<int>,less<int>> que;
    for (int i=0;i<n;i++){
        int temp;
        cin>>temp;
        que.push(temp);
    }
    
    for (int i=0;i<m;i++){
        int x=que.top();
        que.pop();
        que.push((int)floor(x/2));
    }
    long long int ans=0;
    while(!que.empty()){
        ans+=que.top();
        que.pop();
    }
    cout<<ans<<endl;
    return 0;
}