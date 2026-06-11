#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    int N, M;
    cin >> N >> M;

    priority_queue<int> pq;
    
    rep(i, N) {
        int A;
        cin >> A;
        pq.push(A);
    }

    rep(i,M){
        int A = pq.top();
        pq.pop();
        pq.push(A/2);
    }

    ll ans = 0;
    while(!pq.empty()){
        int A = pq.top();
        pq.pop();
        ans+=A;
    }
    cout << ans << '\n';
}
