#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    ll a, b, k;
    cin >> a >> b >> k;
    ll ap = max((ll)0, a-k);
    ll bp = max((ll)0, min(b, a+b-k));
    printf("%lld %lld\n", ap, bp);
    return 0;
}