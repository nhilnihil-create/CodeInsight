#include <bits/stdc++.h>
using ll = long long;
using namespace std;
ll GCD(ll a, ll b){ return a ? GCD(b % a, a) : b; }
int main(){
    int x,y,a,b,c;
    cin>>x>>y>>a>>b>>c;
    vector<ll> p(a),q(b),r(c);
    for(auto &i:p) cin>>i;
    for(auto &i:q) cin>>i;
    for(auto &i:r) cin>>i;
    sort(p.begin(),p.end(),greater<>());
    sort(q.begin(),q.end(),greater<>());
    priority_queue<ll,vector<ll>,greater<ll>> ppq,qpq;
    priority_queue<ll> rpq;
    for(int i=0; i<x; i++) ppq.push(p[i]);
    for(int i=0; i<y; i++) qpq.push(q[i]);
    for(int i=0; i<c; i++) rpq.push(r[i]);
    for(int i=0; i<c; i++){
        ll pt = ppq.top();
        ll qt = qpq.top();
        ll rt = rpq.top();
        if(rt<pt && rt<qt) break;
        else if(pt<qt){
            ppq.pop();
            rpq.pop();
            ppq.push(rt);
        }else{
            qpq.pop();
            rpq.pop();
            qpq.push(rt);
        }
    }
    ll ans = 0;
    while(!ppq.empty()){
        ans+=ppq.top();
        ppq.pop();
    }
    while(!qpq.empty()){
        ans+=qpq.top();
        qpq.pop();
    }
    cout<<ans<<endl;
    
}