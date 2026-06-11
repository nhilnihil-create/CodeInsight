#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

ll n,m,v,p;
vector<ll> a;

bool C(ll x){
    if(x < p) return true;
    ll now = a[x] + m;
    if(a[p-1] > now) return false;
    ll score = 0;
    score += (p-1) * m;
    score += (n-x) * m;
    for(ll i = p-1;i < x; i++){
        score += min(m,max(0ll, now - a[i]));
    }
    return score >= m * v;
}

int main(){
    cin >> n >> m >> v >> p;
    a.resize(n,0);
    rep(i,n) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());
    
    ll ok = -1;
    ll ng = n;

    while(abs(ng-ok) > 1){
        ll mid = (ok+ng)/2;
        if(C(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok + 1 << endl;
    return 0;
}