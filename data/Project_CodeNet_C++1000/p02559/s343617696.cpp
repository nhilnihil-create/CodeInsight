#include <bits/stdc++.h>

#define PB emplace_back

using namespace std;

const int N = 5e5+100;

long long int fen[N];

void upd(int x, long long int val) {
    for(; x < N - 10; x += (x & (-x))) fen[x] += val;
}

long long int que(int x) {
    long long int ret = 0;
    for(; x >= 1; x -= (x & (-x))) ret+=fen[x];
    return ret;
}

long long int query(int l, int r) {
    return que(r) - que(l-1);
}

int main () {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++ ) {
        long long int val;
        cin >> val;
        upd(i + 1, val);
    }
    while(m--) {
        int t, l, r;
        cin >> t>> l >> r;
        if(t == 0) {
            upd(l + 1, r);
        }
        else {
            cout << query(l+1 , r) << '\n';
        }
    }
}
