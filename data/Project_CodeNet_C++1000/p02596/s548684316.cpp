#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int a[1000001];
int main() {
    int k;
    cin >> k;
    a[1] = 7%k;
    for (int i = 2; i<=k; ++i) a[i]=(10*a[i-1] + 7)%k;
    for (int i = 1; i <= k; ++i) {
        if (a[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
    return 0;
}