#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long
#define endl '\n'
int main()
{
    Hello
    int n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> v;
    priority_queue<int> pq;
    v.resize(1e5 + 5);
    for(int i = 0, a, b; i < n; i++){
        cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= m; i++){
        for(int j = 0; j < v[i].size(); j++)
            pq.push(v[i][j]);
        if(pq.size()){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
    return 0;
}