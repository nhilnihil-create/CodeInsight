#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,ll>;

int n, cur = 0;
vector<vector<int>> hen;
vector<vector<int>> id(1005, vector<int>(1005, -1));
vector<int> dp;
bool is_dag = true;

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            id[i][j] = cur++;
        }
    }   
    dp.resize(cur);
    hen.resize(cur);
}

int value(int i, int j) {
    if(i > j)swap(i, j);
    return id[i][j];
}

int dfs(int v) {
    if(dp[v] != 0) {
        if(dp[v] > 0) {
            return dp[v];
        }else {
            is_dag = false;
            dp[v] = -2;
            return -1;
        }
    }

    int now = dp[v];
    dp[v] = -1;
    for(auto i : hen[v]) {
        now = max(now, dfs(i) + 1);
    }
    dp[v] = now;
    return dp[v];
}


int main()
{
    cin >> n;
    init();

    for(int i = 0; i < n; i++) {
        int s; cin >> s; s--;
        s = value(i, s);
        for(int j = 0; j < n - 2; j++) {
            int a; cin >> a; a--;
            hen[s].push_back(value(i, a));
            s = value(i, a);
        }
    }

    for(int i = 0; i < cur; i++) {
        dfs(i);
    }
    
    cout << (is_dag ? *max_element(dp.begin(), dp.end()) + 1 : -1) << endl;

}