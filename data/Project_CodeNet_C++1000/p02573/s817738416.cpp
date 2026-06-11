#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iomanip>
#include <cmath>
#include <chrono>

#define vi vector<int>
#define tests int t; cin>>t; while(t--)
#define ll long long
#define vll vector<long long>
#define srt(v) sort(v.begin(), v.end())
#define srtg(v) sort(v.begin(), v.end(), greater<int> ())
#define FOR(k, n) for(int k=0; k<n; k++)
#define pb push_back


using namespace std;
using namespace std::chrono;

char nums[10] = { '0','1','2','3','4','5','6','7','8','9' };
char alphsl[26] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
const int MOD = 1000000007;
char alphs[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };

int visited[200001];
int sizy = 0;
vector<vector<int>> adj(200005);

void dfs(int a) {
    if (visited[a] == 1) return;
    visited[a] = 1;
    sizy++;
    for (auto x : adj[a]) {
        if (visited[x] == 0) dfs(x);
    }

}



void solve() {

    int n, m;
    cin >> n >> m;

    
    vector<set<int>> present(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (present[a].count(b) == 0) {
            adj[a].pb(b);
            adj[b].pb(a);
            present[a].insert(b);
            present[b].insert(a);
        }
    }
    int maxy = 0;
    for (int i = 1; i <= n; i++) {
        if (visited[i] == 1) {
            continue;
        }
        if (visited[i] == 0) {
            sizy = 0;
            dfs(i);
            maxy = max(sizy, maxy);
        }
    }

    cout << maxy << endl;
    

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);

        
        solve();


    return 0;
}