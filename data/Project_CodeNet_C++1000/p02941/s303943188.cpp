#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    priority_queue<pair<ll, int>> pq;
    for (int i = 0; i < N; i++) {
        cin >> B[i];
        if (A[i] < B[i]) {
            pq.push({B[i], i});
        }
        if (A[i] > B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = 0;
    while (!pq.empty()) {
        int pos = pq.top().second;
        pq.pop();
        int pre = (pos+N-1)%N;
        int nxt = (pos+1)%N;
        ll dist = B[pre]+B[nxt];
        if (dist > B[pos]-A[pos]) {
            cout << -1 << endl;
            return 0;
        }
        ans += (B[pos]-A[pos])/dist;
        B[pos] -= (B[pos]-A[pos])/dist*dist;
        if (B[pos] > A[pos]) pq.push({B[pos], pos});
    }
    cout << ans << endl;
    return 0;
}
