#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T>
using vec = std::vector<T>;

int main() {
    int A,B,M;
    cin >> A >> B >> M;
    vec<int> a(A),b(B);
    int minA = 99999999;
    int minB = 99999999;
    rep(i,A) {
        cin >> a[i];
        minA = min(minA, a[i]);
    }
    rep(i,B) {
        cin >> b[i];
        minB = min(minB, b[i]);
    }
    int ans = minA +minB;
    vec<int> x(M),y(M),c(M);
    rep(i,M) {
        int x,y,c;
        cin >> x >> y >> c;
        --x,--y;
        ans = min(ans,a[x]+b[y]-c);
    }
    cout << ans << endl;
}