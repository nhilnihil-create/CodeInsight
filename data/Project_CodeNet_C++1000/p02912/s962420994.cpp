#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int N,M;
    cin >> N >> M;
    vector<int>A(N);
    priority_queue<int,vector<int>,less<int>> que;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        que.push(A[i]);
    }
    while(M != 0) {
        M--;
        int X = que.top();
        X/=2;
        que.pop();
        que.push(X);
    }
    int ans = 0;
    while(!que.empty()) {
        ans+=que.top();
        que.pop();
    }
    cout << ans << endl;
}
