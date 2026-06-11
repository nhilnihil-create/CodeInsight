#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
using ll = long long int;
const int MAX_NUM = 2 * 1e5 + 10;
vector<int> a(MAX_NUM, 0);
vector<int> b(MAX_NUM, 0);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    priority_queue<pair<int, int>> pq;
    int n; cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i]; 
    }
    for(int i=0; i<n; i++){
        cin >> b[i]; 
        if(b[i] != a[i]){
            pq.push(pair<int, int>{b[i], i});
        }
    }

    ll ans = 0;
    while(!pq.empty()){
        pair<int, int> maxp = pq.top(); pq.pop();
        ll m = maxp.first; int id = maxp.second;
        ll l = b[(id + n - 1) % n];
        ll r = b[(id + 1) % n];
        ll div = m / (l + r);
        if((m - a[id]) % (l + r) == 0){
            div = (m - a[id]) / (l + r);
            ans += div;
            b[id] = a[id];
            continue;
        }
        if(l + r >= m){
            cout << -1 << endl;
            return 0;
        }
        m %= (l + r);
        ans += div;
        b[id] = m;
        // for(int i=0; i<n; i++){
        //     cout << b[i] << " ";
        // }
        // cout << endl;
        if(m < a[id]){cout << -1 << endl; return 0;}
        pq.push(pair<int, int>{m, id});
    }

    cout << ans << endl;
    return 0;
}