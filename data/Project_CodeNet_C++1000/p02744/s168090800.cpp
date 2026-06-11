//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int n;
vvi s;
void dfs(int i, int j, int ma) {
    if(i == n) return;
    s[j].push_back(0);
    vi a = s[j];
    
    while(true) {
        dfs(i+1, j, max(a[i]++ + 2, ma));
        if(a[i] == n || a[i] == ma) break;
        s.push_back(a);
        j = s.size()-1;
    }
}

int main() {
    cin >> n;
    vi a(1);
    s.push_back(a);
    dfs(1, 0, 2);
    vs xx;
    rep(i, s.size()) {
        if(s[i].size() != n) continue;
        xx.push_back("");
        rep(j, n) {
            xx[xx.size()-1].push_back(s[i][j] + 'a');
        }
    }  

    sort(all(xx));
    rep(i, xx.size()) {
        cout << xx[i] << '\n';
    }
}