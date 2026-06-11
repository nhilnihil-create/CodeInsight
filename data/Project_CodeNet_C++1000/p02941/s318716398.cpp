#include<bits/stdc++.h>

using namespace std;

#define fi first
#define se second

using ll = long long;

const int N = (int)2e5 + 5;
int n, a[N], b[N];
ll ans;
priority_queue< pair<int, int> > pq;

int nxt(int i) { return i == n - 1 ? 0 : i + 1; }
int prv(int i) { return i == 0 ? n - 1 : i - 1; }

void kill() { printf("-1"); exit(0); }

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", a + i);
    for (int i = 0; i < n; ++i) {
        scanf("%d", b + i);
        if (b[i] < a[i]) kill();
        else if (b[i] > a[i]) pq.push( { b[i], i } );
    }

    while (!pq.empty() ) {
        int i = pq.top().se; pq.pop(); int l = prv(i), r = nxt(i);
        if (b[i] <= b[l] + b[r]) kill();
        int nB = b[i] % (b[l] + b[r]);
        if (nB >= a[i]) {
            ans += b[i] / (b[l] + b[r]);
            b[i] = nB;
            if (b[i] > a[i]) pq.push( { b[i], i } );
        }
        else {
            if ( (b[i] - a[i]) % (b[l] + b[r]) ) kill();
            else {
                ans += (b[i] - a[i]) / (b[l] + b[r]);
                b[i] = a[i];
            }
        }
    }

    cout << ans;

    return 0;
}
