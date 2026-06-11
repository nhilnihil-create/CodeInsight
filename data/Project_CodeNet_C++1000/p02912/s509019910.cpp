#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    long long sum=0;
    cin>>n>>m;
    priority_queue<int>Q;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        Q.push(a);
    }
    for(int i=0;i<m;i++){
        int t=Q.top();
        Q.pop();
        t/=2;
        Q.push(t);
    }
    for(int i=0;i<n;i++){
        sum+=Q.top();
        Q.pop();
    }
    cout<<sum<<"\n";
    return(0);
}