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

int n;
int v[1000][1000];

void solve(vector<int>& elm, int col){
    int m = elm.size();
    if(m == 1)
        return;
    vector<int> a, b;
    for(int i = 0; i < m; ++i)
        (i % 2 ? b : a).push_back(elm[i]);
    for(auto x : a)
        for(auto y : b)
            v[x][y] = col;
    solve(a, col + 1);
    solve(b, col + 1);
}

signed main(){

    cin >> n;
    vector<int> t(n);
    iota(t.begin(), t.end(), 0);
    solve(t, 1);
    for(int i = 0; i < n; ++i)
        for(int j = i + 1; j < n; ++j)
            cout << max(v[i][j], v[j][i]) << " \n"[j == n - 1];

}
