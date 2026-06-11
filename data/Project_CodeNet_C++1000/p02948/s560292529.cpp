#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
signed main() {
    int N,M;
    cin >> N >> M;
    vector<vector<int>>AB(M+1);
    priority_queue<int, vector<int>, less<int>> que;
    for(int i = 0; i < N; i++) {
        int A,B;
        cin >> A >> B;
        if(A > M) {
            continue;
        }
        AB[A-1].push_back(B);
    }
    int ans = 0;
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < AB[i].size(); j++) {
            que.push(AB[i][j]);
        }
        if(que.empty()) {
            continue;
        }
        ans+=que.top();
        que.pop();
    }
    cout << ans << endl;
}