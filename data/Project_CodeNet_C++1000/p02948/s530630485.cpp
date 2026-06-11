#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair


int main(){
    ll n,m;
    cin >> n >> m;
    ll a[n],b[n];
    vector<ll> t[100005];
    for(ll i=0;i<n;i++){
        cin >> a[i] >> b[i];
        t[a[i]].push_back(b[i]);
    }
    priority_queue<ll> pq;
    ll res=0;
    for(ll i=1;i<=m;i++){
        for(auto p:t[i]){
            pq.push(p);
        }
        if(!pq.empty()){
            res+=pq.top();
            pq.pop();
        }
    }
    cout << res << endl;
}
