#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define rep(i,n) for(ll i=0;i<(ll)n;i++)

int main(){
    int n,m; cin >> n >> m;
    vector<int> a(n+1);
    priority_queue<int> pq;
    rep(i,n){
        cin >> a[i];
        pq.push(a[i]);
    }
    rep(i,m){
        int x = pq.top();
        x /= 2;
        pq.pop();
        pq.push(x);
    }
    ll res=0;
    while(!pq.empty()){
        res += pq.top();
        pq.pop();
    }
    cout << res << endl;
}