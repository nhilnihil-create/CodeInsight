#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
    ll x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<int> p(a),q(b),r(c);
    for(int i=0;i<a;i++) cin>>p[i];
    for(int i=0;i<b;i++) cin>>q[i];
    for(int i=0;i<c;i++) cin>>r[i];
    sort(p.rbegin(),p.rend());
    sort(q.rbegin(),q.rend());
    priority_queue<int> t;
    for(int i=0;i<x;i++) t.push(p[i]);
    for(int i=0;i<y;i++) t.push(q[i]);
    for(int i=0;i<c;i++) t.push(r[i]);
    ll ans=0;
    for(int i=0;i<x+y;i++){
        ans+=t.top();
        t.pop();
    }
    cout<<ans<<endl;
}