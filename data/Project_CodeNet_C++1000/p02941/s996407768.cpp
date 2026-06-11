#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 998244353;
const i64 INF = i64(1e18) + 7;


template <typename T>
bool chmin(T& x, T y){
    if(x > y){
        x = y;
        return true;
    }
    return false;
}

template <typename T>
bool chmax(T& x, T y){
    if(x < y){
        x = y;
        return true;
    }
    return false;
}


signed main(){
    int n;
    cin >> n;
    vector<i64> a(n), v(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    for(int i = 0; i < n; ++i)
        cin >> v[i];
    priority_queue<pair<i64,int>> que;
    for(int i = 0; i < n; ++i)
        que.emplace(v[i], i);
    i64 ans = 0;
    while(!que.empty()){
        i64 val;
        int i;
        tie(val, i) = que.top();
        que.pop();
        i64 su = v[(i + 1) % n] + v[(i + n - 1) % n];
        i64 ma = max({v[(i + 1) % n], v[(i + n - 1) % n], a[i]});

        i64 diff = val - ma;
        i64 cnt = (diff + su - 1) / su;
        ans += cnt;
        val -= su * cnt;
        v[i] = val;
        if(val > a[i])
            que.emplace(val, i);
        if(val < a[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << (a == v ? ans : -1) << endl;
}

