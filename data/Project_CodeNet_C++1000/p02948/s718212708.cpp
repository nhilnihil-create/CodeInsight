#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int n, m;
    cin >> n >> m;
    map<int,vector<int>> a;
    for(int i = 0; i < n; i++){
        int t, k; cin >> t >> k;
        a[t].push_back(k);
    }

    priority_queue<int> que;
    int sum = 0;
    for(int i = 0; i <= m; i++) {
        for(auto j : a[i]) {
            que.push(j);
        }
        if(que.empty())continue;
        sum += que.top();
        que.pop();
    }
    cout << sum << endl;

}