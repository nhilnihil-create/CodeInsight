#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    rep(i,n) cin >> a[i];
    priority_queue<P> pq;
    rep(i,n){
        cin >> b[i];
        pq.emplace(b[i], i);
    }
    ll ans = 0;
    while(!pq.empty()){
        P ele = pq.top();
        pq.pop();
        if(a[ele.second] > ele.first){
            cout << -1 << endl;
            return 0;
        }
        if(a[ele.second] == ele.first) continue;
        int nextLeft = (ele.second + n - 1) % n;
        int nextRight = (ele.second + 1) % n;
        ll vLeft = b[nextLeft];
        ll vRight = b[nextRight];
        vector<P> v;
        while(ele.first <= (vLeft + vRight)){
            v.push_back(ele);
            if(pq.empty()){
                cout << -1 << endl;
                return 0;
            }
            ele = pq.top();
            pq.pop();
            nextLeft = (ele.second + n - 1) % n;
            nextRight = (ele.second + 1) % n;
            vLeft = b[nextLeft];
            vRight = b[nextRight];
        }
        for(auto p : v){
            pq.push(p);
        }
        ll x = (ele.first - (vLeft + vRight) + (vLeft + vRight - 1)) / (vLeft + vRight);
        ll y = (ele.first - a[ele.second]) / (vLeft + vRight);
        ll z = min(x, y);
        ans += z;
        b[ele.second] = ele.first - z * (vLeft + vRight);
        if(b[ele.second] < a[ele.second]){
            cout << -1 << endl;
            return 0;
        }
        else if(b[ele.second] > a[ele.second]){
            if(b[ele.second] > (vLeft + vRight)){
                x = (b[ele.second] - (vLeft + vRight) + (vLeft + vRight - 1)) / (vLeft + vRight);
                ans += x;
                b[ele.second] -= x * (vLeft + vRight);
                if(b[ele.second] < a[ele.second]){
                    cout << -1 << endl;
                    return 0;
                }
                else if(b[ele.second] == a[ele.second]) continue;
            }
            pq.emplace(b[ele.second], ele.second);
        }
    }
    cout << ans << endl;
    return 0;
}
