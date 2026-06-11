#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<int> pq;
    rep(i,n){
        int a;
        cin>>a;
        pq.push(a);
    }
    rep(i,m){
        pq.push(pq.top()/2);
        pq.pop();
    }
    ll ans=0;
    while(!pq.empty()){
        ans+=pq.top();
        pq.pop();
    }
    cout<<ans<<endl;
}