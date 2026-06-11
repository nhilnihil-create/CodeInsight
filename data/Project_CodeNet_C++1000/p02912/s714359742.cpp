#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,s,z,p=0;
    priority_queue<long long> q;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s;
        q.push(s);
    }
    for(int i=0;i<m;i++){
        z=q.top();
        q.pop();
        z/=2;
        q.push(z);
    }
    for(int i=0;i<n;i++){
        p+=q.top();
        q.pop();
    }
    cout<<p<<'\n';
    return(0);
}