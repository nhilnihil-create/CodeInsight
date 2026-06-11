#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const ll mod = 1e9+7;

vector<int> num;
vector<vector<int>> hen;
vector<bool> seen;
int n, k;

void dfs_cnt(int c)
{
    int cur = (c == 0 ? k : k - 1);
    for(auto i : hen[c])
    {
        if(seen[i])continue;
        seen[i] = true;
        if(cur == 0)cur = 1;
        num[i] = --cur;
        dfs_cnt(i);
    }
}


int main()
{
    cin >> n >> k;
    hen.resize(n);
    num.resize(n);
    seen.resize(n);
    for(int i = 0; i < n - 1; i++){
        int a,b; cin >> a >> b; a--; b--;
        hen[a].push_back(b);
        hen[b].push_back(a);
    }

    seen[0] = true;
    num[0] = k;
    dfs_cnt(0);

    ll ans = 1;
    for(int i = 0; i < n; i++){
        ans *= num[i];
        ans %= mod;
    }
    cout << ans << endl;





}