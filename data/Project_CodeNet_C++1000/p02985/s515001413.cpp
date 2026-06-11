#include <iostream>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
using namespace std;

int n, k, t1, t2, m = 1e9 + 7, dp[100005];
vector<int> g[100005];

int f(int p, int pr) {
    if(dp[p] != -1)
        return dp[p];
    int c = 1;
    if(pr == -1)
        c = k;

    int j = 2;
    if(pr == -1)
        j = 1;
        
    for(int i: g[p])
        if(i != pr)
            c = 1ll * c * f(i, p) % m * (k - (j++)) % m;
    return dp[p] = c;
}

int main() {
    cin >> n >> k;
    memset(dp, -1, sizeof dp);
    for(int i = 0; i < n - 1; ++i)
        cin >> t1 >> t2, g[t1].push_back(t2), g[t2].push_back(t1);
    
    cout << f(1, -1) << endl; 
    return 0;
}