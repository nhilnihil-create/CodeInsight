#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int N, K, C;
vector<int> sub(const string &S) {
    int N = S.size();
    int cur = 0, last = - C - 1;
    vector<int> res(N+1, 0);
    rep(i, N) {
        if(i - last > C && S[i] == 'o') ++cur, last = i;
        res[i+1] = cur;
    }
    return res;
}

void solve(const string &S) {
    const auto &left = sub(S);
    string T = S;
    reverse(T.begin(), T.end());
    const auto &right = sub(T);
    rep(i, N) {
        if(S[i] == 'x') continue;
        if(left[i] + right[N-i-1] < K) cout << i+1 << endl;
    }
}

int main() {
    string S;
    cin >> N >> K >> C >> S;
    solve(S);
    return 0;
}