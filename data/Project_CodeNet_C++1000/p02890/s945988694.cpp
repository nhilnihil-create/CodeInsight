#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

const i64 MOD = 1e9 + 7;
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
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin >> a[i];

    unordered_map<int,int> m;
    for(int i = 0; i < n; ++i)
        ++m[a[i]];
    vector<int> v;
    for(auto& p : m)
        v.push_back(p.second);
    sort(v.begin(), v.end());
    vector<int> rui(n + 1, 0);
    vector<i64> cnt(n + 1, 0);
    for(int i = 0; i < v.size(); ++i)
        ++rui[v[i]];
    for(int i = n; i > 0; --i){
        cnt[i - 1] = cnt[i] + rui[i];
        rui[i - 1] += rui[i];
    }

    // rui[k]: k以上の物の数

    // k減らすのをc回できるかどうか
    auto f = [&](int k, int c){
        return n - cnt[c] >= 1LL * k * c;
    };

    for(int k = 1; k <= n; ++k){
        int ok = 0, ng = n + 1;
        while(ng - ok > 1){
            int mid = (ok + ng) / 2;
            (f(k, mid) ? ok : ng) = mid;
        }
        printf("%d\n", ok);
    }
}

