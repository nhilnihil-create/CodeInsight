#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    ll N,M;
    cin >> N >>M;
    vector<pair<ll,ll>> X;
    for(int i=0;i<N;i++){
        ll a,b;
        cin >> a >>b;
        --a;
        X.emplace_back(a,b);
    }
    sort(X.begin(),X.end());
    priority_queue<ll> pq;
    ll t=0;
    ll ans =0;
    for(int i=0;i<M;i++){
        while(t<N &&X[t].first == i){
            pq.push(X[t].second);
            t++;
        }
        if(!pq.empty()){
            int a = pq.top();pq.pop();
            ans +=a;
        }
    }
    cout << ans << endl;

    return 0;
}