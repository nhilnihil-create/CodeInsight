#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    priority_queue<int> hp;
    for(int i=0;i<n;i++){
        int h;
        cin>>h;
        hp.push(h);
    }
    for(int i=0;i<k&&!hp.empty();i++){
        hp.pop();
    }
    long long ans=0;
    while(!hp.empty()){
        ans+=hp.top();
        hp.pop();
    }
    cout<<ans<<"\n";
    return(0);
}