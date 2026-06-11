#include <iostream>
#include <queue>
using namespace std;
int N, M;
int A[100100];

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];
    priority_queue<int> que;
    for (int i = 0; i < N; i++) que.push(A[i]);

    for (int i = 0; i < M; i++) {
        int cost = que.top(); que.pop();
        cost /= 2; 
        que.push(cost);
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        ans += que.top(); que.pop(); 
    }
    cout << ans << endl;
}