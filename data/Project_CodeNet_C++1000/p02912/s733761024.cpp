#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    int N, M;
    cin >> N >> M;

    priority_queue<ll> que;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        que.push(A);
    }

    for (int i = 0; i < M; i++)
    {
        ll front = que.top();
        que.pop();
        front /= 2;
        que.push(front);
    }
    
    ll ans = 0;
    while(!que.empty()){
        ans += que.top();
        que.pop();
    }

    cout << ans << endl;
    
    return 0;
}
