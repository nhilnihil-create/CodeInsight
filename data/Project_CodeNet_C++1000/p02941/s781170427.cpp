#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
//const ll mod = 1000000007;
int N;
ll A[205000], B[205000];
priority_queue<l_l> que;

void add(int i) {
    if(A[i] == B[i]) return;
    ll a = B[(i+1)%N];
    chmax(a, B[(i+N-1)%N]);
    if(a <= B[i]) {
        que.push({B[i] - a, i});
    }
    return;
}

int main() {
    //cout.precision(10);
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) {
        if(B[i] < A[i]) {
            cout << -1 << endl;
            return 0;
        }
        add(i);
        /*
        ll a = B[(i+N-1)%N];
        chmin(a, B[(i+1)%N]);
        if(B[i] >= a) {
            que.push({B[i] - a, i});
        }
        */
    }
    ll ans = 0;
    while(!que.empty()) {
        l_l now = que.top();
        que.pop();
        int i = now.second;
        ll val = B[(i+N-1)%N] + B[(i+1)%N];
        ll num = B[i] / val;
        chmin(num, (B[i] - A[i]) / val);
        //cerr << i << " " << val << " " << num << endl;
        if(num == 0 && A[i] != B[i]) {
            cout << -1 << endl;
            return 0;
        }
        if(num == 0) continue;
        ans += num;
        B[i] -= val * num;
        add((i + 1) % N);
        add((i + N - 1) % N);
    }
    for(int i = 1; i <= N; i++) {
        if(A[i] != B[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}
