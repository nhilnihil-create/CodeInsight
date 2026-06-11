#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repr(i, a, b) for(int i = a; i < b; i++)
#define  all(x) (x).begin(),(x).end()     // 昇順ソート
#define  rall(v) (v).rbegin(), (v).rend() // 降順ソート
#define  FastIO ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef long long int lli;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return true; } return false; }

int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int main(){
    int n;
    cin >> n;
    vector<vector<int>> g(n+1);
    vector<pair<int, int>> ab(n-1);
    rep(i,n-1){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        ab[i] = make_pair(a, b);
    }

    map<pair<int, int>, int> cols;
    vector<int> pre(n+1, -1);
    queue<int> q;
    q.push(ab[0].first);
    int maxCol = 0;
    while(!q.empty()){
        int v = q.front(); q.pop();
        int col = 1;
        int vp = pre[v];
        int usedCol = cols[make_pair(v, vp)];
        for(int vc: g[v]){
            pair<int, int> vvc, vcv;
            vvc = make_pair(v, vc);
            vcv = make_pair(vc, v);
            if (cols[vvc] != 0 || cols[vcv] != 0) continue;
            if (col == usedCol) col++;
            cols[vvc] = cols[vcv] = col;
            col++;
            pre[vc] = v;
            q.push(vc);
        }
        maxCol = max(maxCol, col-1);
    }
    cout << maxCol << endl;
    rep(i,n-1){
        cout << cols[ab[i]] << endl;
    }
}