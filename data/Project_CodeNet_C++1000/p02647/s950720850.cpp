#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

typedef long long LL;

const int N = 200009;
int n, k, a[N], b[N];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    LL tot = 0, mx = (LL)n*n;
    for(int i = 0; i < n; ++i) {
        b[i] = a[i];
        tot += b[i];
    }

    for(int i = 0; i < k && tot < mx; ++i) {
        vector<int> rg(n+1, 0);
        for(int j = 0; j < n; ++j) {
            int l = max(0, j-b[j]), r = min(n, j+b[j]+1);
            rg[l]++;
            rg[r]--;
        }

        int cur = 0;
        tot = 0LL;
        for(int j = 0; j < n; ++j) {
            cur += rg[j];
            b[j] = cur;
            tot += b[j];
        }
    }

    for(int i = 0; i < n; ++i) {
        cout << b[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}
