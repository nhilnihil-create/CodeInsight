#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int N, M, Q;
vector<int> a, b, c, d;

ll solve(const vector<int> &A) {
    ll cnt = 0;
    for (int i = 0; i < Q; i++) {
        if (A.at(b.at(i)) - A.at(a.at(i)) == c.at(i)) {
            cnt += d.at(i);
        }
    }
    return cnt;
}

ll dfs(vector<int> &A) {
    if (A.size() == N) {
        return solve(A);
    }
    ll last, ans = 0;
    if (A.size() == 0) {
        last = 0;
    }    
    else {
        last = A.back();
    }
    for (int u = last; u < M; u++) {
        A.push_back(u);
        ans = max(ans, dfs(A));
        A.pop_back();
    }
    return ans;
}

int main() {
    cin >> N >> M >> Q;
    a.resize(Q); b.resize(Q); c.resize(Q); d.resize(Q);
    for (int i = 0; i < Q; i++) {
        cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
        a.at(i)--, b.at(i)--;
    }
    vector<int> A;
    cout << dfs(A) << endl;
    return 0;
}