#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <string>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <map>
#include <unordered_map>
#include <bitset>

#define _crt_secure_no_warnings
#define FREEELO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define MAX 200001
#define MOD 1000000007
#define ALPHABET 128
#define loop(i, n) for (int i = 1; i <= (n); i++)
#define loop0(i, n) for (int i = 0; i < (n); i++)
#define sz(x) (int)x.size()
#define all(v) v.begin(), v.end()
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll, ll> llll;
typedef pair<int, int> ii;
typedef unordered_map<int, int> umii;
typedef unordered_map<ll, ll> umll;
int cnt = 0;
vector<vector<int> > g;
int used[MAX];
void dfs(int v){
    used[v] = 1;
    cnt++;
    for (int &to : g[v]){
        if (!used[to]) dfs(to);
    }
}

int main(){
    FREEELO
    int n, m; cin >> n >> m;
    g.resize(n + 1);
    loop(i, m){
        int u, v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int mx = -INF;
    loop(i, n){
        if (!used[i]) {
            cnt = 0;
            dfs(i);
            mx = max(mx, cnt);
        }
    }
    cout << mx << endl;
}