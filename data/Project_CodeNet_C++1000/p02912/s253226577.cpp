#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;

    priority_queue<int> q;
    int a;
    for(int i=1;i<=n;i++){
        cin>>a;
        q.push(a);
    }
    
    int temp;
    for(int i=1;i<=m;i++){
        temp=q.top();
        temp/=2;

        q.pop();
        
        q.push(temp);
    }

    long long ans=0;
    for(int i=1;i<=n;i++){
        ans+=q.top();
        q.pop();
    }

    cout<<ans<<"\n";
    return 0;
}