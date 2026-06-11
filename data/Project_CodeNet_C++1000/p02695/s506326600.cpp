#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353
#define Graph vector<vector<int>>

int N, M, Q;
vector<int> a, b, c, d;
ll ans = 0;

ll solve(vector<int> &A) {
    ll cnt = 0;
    for (int i = 0; i < Q; i++) {
        if (A.at(b.at(i) - 1) - A.at(a.at(i) - 1) == c.at(i)) {
            cnt += d.at(i);
        }
    }
    return cnt;
}

ll dfs(vector<int> &A) {
    if (A.size() == N) {
        ans = max(ans, solve(A));
        return ans;
    }
    
    int prev;
    if (A.size() == 0) {
        prev = 1;
    }
    else {
        prev = A.back();
    }
    
    for (int v = prev; v <= M; v++) {
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
    return ans;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q), b.resize(Q), c.resize(Q), d.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
    }
    vector<int> A;
    cout << dfs(A);
    return 0;
}