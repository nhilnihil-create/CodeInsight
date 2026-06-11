#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;
typedef map<string, int> msi;
typedef pair<int, int> PII;

int ans = 0;
vector<vector<int>> v;
vector<int> h;

void func(int n){
    rep(i, n){
        int temp = h.at(i);
        bool flag = true;
        for(auto x : v.at(i)){
            if(temp <= h.at(x)) flag = false;
        }
        if(flag) ans++;
    }
}

int main() {
    int n, m; cin >> n >> m;
    h = vector<int>(n);
    rep(i, n){
        int x; cin >> x;
        h.at(i) = x;
    }
    v.resize(n);
    rep(i, m){
        int x, y; cin >> x >> y;x--;y--;
        v.at(x).push_back(y);
        v.at(y).push_back(x);

    }
    func(n);
    cout << ans << endl;
    return 0;
}