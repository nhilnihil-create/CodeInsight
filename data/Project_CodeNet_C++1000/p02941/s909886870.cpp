#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using P = pair<ll,ll>;

int main() {
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<N;i++){
        cin >> B[i];
    }
    priority_queue<P> pq;
    for(int i=0;i<N;i++){
        ll v = B[i] - B[(N+i-1)%N] - B[(i+1)%N];
        // cerr <<"i=" << i <<"v=" << v << endl;
        if(v>0){
            pq.push(P(v,i));
        }
    }
    ll ans = 0;
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        // cerr <<"t=" << p.second <<", val= " << p.first << endl;
       
        if(p.first  <A[p.second]){
            continue;
        }
        ll diff = B[p.second] - p.first;
        if(diff==0){
            continue;
        }
        ll n = (B[p.second] - A[p.second])/diff;
        B[p.second] -= diff*n;
        ans += n;
        for(int i=-1;i<2;i++){
            ll ni = (p.second + i +N)%N;
            ll v = B[ni] - B[(N+ni-1)%N] - B[(ni+1)%N];
            // cerr <<"ni=" << ni <<"v=" << v <<endl;
            if(v>0){
                pq.push(P(v,ni));
            }
        }
    }
    for(int i=0;i<N;i++){
        if(A[i] != B[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;

    

    return 0;
}