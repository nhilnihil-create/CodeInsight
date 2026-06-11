#include <iostream>
#include <queue>
using namespace std;

int main(){
    int n, m; cin >> n >> m;
    priority_queue<int> pq;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        pq.push(a);
    }
    for (int i = 0; i < m; ++i) {
        int num = pq.top();
        pq.pop();
        pq.push(num / 2);
    }
    long long ans = 0;
    while (!pq.empty()) {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
}