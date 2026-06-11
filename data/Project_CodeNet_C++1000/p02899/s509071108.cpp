#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n,a; cin >> n;
    int ans[n];
    rep(i,n) {
        cin >> a;
        ans[a-1] = i+1;
    }
    rep(i,n) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
