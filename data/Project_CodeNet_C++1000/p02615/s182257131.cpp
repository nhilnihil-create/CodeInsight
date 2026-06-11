#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>());
    int now = 0;
    long long ans = 0;
    priority_queue<int> pq;
    pq.push(a[now++]);
    for (; now < n; now++) {
        ans += pq.top();
        pq.pop();
        pq.push(a[now]);
        pq.push(a[now]);
    } 
    cout << ans << endl;
}