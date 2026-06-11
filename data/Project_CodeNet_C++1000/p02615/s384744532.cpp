#include<bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (int)(n); i++)
#define sum(a) accumulate(a.begin(),a.end(),0LL)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    vector<ll> a(n); rep(i,n) cin >> a[i];

    ll ans = 0;
    sort(a.begin(),a.end(),greater<ll>());
    priority_queue<ll> q;
    q.push(a[0]);
    for(long long i = 1; i < n; i++){
        ans += q.top(); q.pop();
        q.push(a[i]);
        q.push(a[i]);
    }
    put(ans);
}