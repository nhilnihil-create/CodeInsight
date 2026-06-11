#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;

string solve() {
    int N; cin >> N;
    vector<int> A(N);
    for(auto &e : A) cin >> e;
    int all = 0;
    for(auto &e : A) all = gcd(all, e);
    if(all != 1) return "not coprime";
    int M = 1e6;
    map<int, int> mp;
    for(auto &e : A) mp[e]++;
    for(int i = 2; i <= M; ++i) {
        int cnt = 0;
        for(int j = i; j <= M; j += i) {
            if(mp.find(j) != mp.end()) cnt += mp[j];
        }
        if(cnt > 1) return "setwise coprime";
    }
    return "pairwise coprime";
}

int main() {
    cout << solve() << '\n';
    return 0;
}
