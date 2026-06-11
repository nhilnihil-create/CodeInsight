#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

vector<int> E[1000005];
int indegree[1000005];
bool finish[1000];

int main() {
    int n; cin >> n;
    int a[n][n-1];
    rep(i,n) rep(j,n-1) {
        cin >> a[i][j];
        a[i][j]--;
    }
    int v1,v2;
    rep(i,n) {
        rep(j,n-2) {
            if (i < a[i][j]) v1 = i*1000+a[i][j];
            else v1 = a[i][j]*1000+i;
            if (i < a[i][j+1]) v2 = i*1000+a[i][j+1];
            else v2 = a[i][j+1]*1000+i;
            E[v1].push_back(v2);
            indegree[v2]++;
        }
    }
    vector<int> topo;
    queue<int> que;
    rep(i,n) {
        for (int j = i+1; j < n; j++) {
            if (indegree[1000*i+j] == 0) {
                que.push(1000*i+j);
            }
        }
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for(int nx : E[v]) {
            indegree[nx]--;
            if (indegree[nx] == 0) que.push(nx);
        }
        topo.push_back(v);
    }
    if (topo.size() != n*(n-1)/2) {
        cout << -1 << endl;
        return 0;
    }

    int ans = 1;
    rep(i,n) finish[i] = true;
    for (int battle : topo) {
        int one = battle / 1000;
        int two = battle % 1000;
        if (finish[one] && finish[two]) {
            finish[one] = false;
            finish[two] = false;
        } else {
            rep(i,n) finish[i] = true;
            ans++;
            finish[one] = false;
            finish[two] = false;
        }
    }

    cout << ans << endl;

    
    return 0;
}
