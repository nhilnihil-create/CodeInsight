#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 1005;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    int N;
    cin >> N;
    vector<vector<int> > table(MAX, vector<int>(MAX));
    for (int i = 0; i < N; i++) for (int j = 0; j < N-1; j++) cin >> table[i][j];
    for (int i = 0; i < N; i++) for (int j = 0; j < N-1; j++) table[i][j]--;

    map<pii, int> mp;
    vector<int> cnt(MAX);
    queue<int> q;
    for (int i = 0; i < N; i++) q.push(i);

    int days = 0;
    while (!q.empty()) {
        queue<int> qn;
        while (!q.empty()) {
            int a = q.front(); q.pop();
            int b = table[a][cnt[a]];
            if (a > b) swap(a, b);
            int c = mp[pii(a, b)]++;
            if (c == 0) continue;
            cnt[a]++, cnt[b]++;
            if (cnt[a] < N - 1) qn.push(a);
            if (cnt[b] < N - 1) qn.push(b);
        }
        q = qn;
        days++;
    }
    bool can = true;
    for (int i = 0; i < N; i++) {
        if (cnt[i] != N-1) can = false;
    }
    if (can) cout << days << '\n';
    else cout << -1 << '\n';
}

