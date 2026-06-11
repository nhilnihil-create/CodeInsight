#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    priority_queue<int> pq;
    for(int i = 0; i < N; i++) {
        int A; cin >> A;
        pq.push(A);
    }
    for(int i = 0; i < M; i++) {
        int n = pq.top(); pq.pop();
        pq.push(n / 2);
    }
    long long sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    cout << sum << endl;
    return 0;
}