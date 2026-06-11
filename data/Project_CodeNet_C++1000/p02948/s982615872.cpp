#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<double,int>;

int main(){
    int n,m;
    cin>>n>>m;
    priority_queue<P,vector<P>,greater<P>>q;
    rep(i,n){
        int a,b;
        cin>>a>>b;
        q.emplace(P(a,b));
    }
    int ans=0,now=0;
    priority_queue<int>q2;
    rep(i,m){
        while(!q.empty()&&i+1>=q.top().first){
            q2.emplace(q.top().second);
            q.pop();
        }
        if(!q2.empty()){
            ans+=q2.top();
            q2.pop();
        }
    }
    cout<<ans<<endl;
}