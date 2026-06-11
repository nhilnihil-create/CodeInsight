#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> rew(m);
    for(int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        if(a>m) continue;
        rew[a-1].emplace_back(b);
    }
    priority_queue<int> pque;
    int ans=0;
    for(int i = 0; i < m; i++) {
        rew[i].emplace_back(0);
        int siz=rew[i].size();
        for(int j = 0; j < siz; j++) {
            pque.push(rew[i][j]);
        }
        int add=pque.top();
        pque.pop();
        ans+=add;
    }
    cout << ans << "\n";
    return 0;
}