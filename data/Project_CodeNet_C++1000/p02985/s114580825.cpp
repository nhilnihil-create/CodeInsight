#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    long int mod = 1000000007;
    long int n, k;
    cin >> n >> k;
    vector<long int> g[n];
    for(int i = 0; i < n - 1; i++){
        long int a, b;
        cin >> a >> b;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int color[n];
    for(int i = 0; i < n; i++) color[i] = 0;
    color[0] = 1;
    queue<long int> q;
    q.push(0);
    long int ans = k;
    while(true){
        if (q.size() == 0) break;
        long int e = q.front();
        int s = g[e].size();
        int decided = 1;
        for(int i = 0; i < s; i++){
            if (color[g[e][i]] != 0) {
                decided++;
            }
        }
        for(int i = 0; i < s; i++){
            if (color[g[e][i]] == 0) {
                color[g[e][i]] = 1;
                ans *= k - decided;
                decided++;
                ans %= mod;
                q.push(g[e][i]);
            }
        }
        // cout << decided << endl;
        q.pop();
    }
    cout << ans << endl;
}