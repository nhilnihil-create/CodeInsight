#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

int n;
vector<ll> a, b;

bool isOK(int i){
    return b[(i-1+n)%n]+b[(i+1)%n] < b[i];
}

int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    priority_queue<P> que;
    for(int i=0;i<n;i++){
        if(isOK(i)){
            que.push({b[i],i});
        }
    }
    ll ans = 0;
    while(!que.empty()){
        P p = que.top();
        que.pop();
        int id = p.second, l = (id-1+n)%n, r = (id+1)%n;
        ll sum = b[l]+b[r];
        if(b[id]-sum < a[id]) continue;
        ans += (b[id]-a[id])/sum;
        b[id] -= (b[id]-a[id])/sum*sum;
        if(isOK(l)) que.push({b[l],l});
        if(isOK(r)) que.push({b[r],r});
    }
    bool ok = true;
    for(int i=0;i<n;i++) ok &= a[i]==b[i];
    cout << (ok ? ans : -1) << endl;
    return 0;
}
