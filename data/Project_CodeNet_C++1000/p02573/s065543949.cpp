#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N, M;
vector<int> x, s;
int par(int a) {
    if (x[a] == a) return a;
    return x[a] = par(x[a]);
}
int ans = 1;
void unite(int a, int b) {
    int pa = par(a), pb = par(b);
    if (pa == pb) return;
    s[pa] += s[pb];
    x[pb] = pa;
    ans = max(ans, s[pa]);
}
int main () {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        x.push_back(i);
        s.push_back(1);
    }
    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--, B--;
        unite(A, B);
    }
    cout << ans << endl;
}