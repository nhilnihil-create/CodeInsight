#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(c) (c).begin(),(c).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)

const int INF = 1e9 + 10;

int K;
ll res = 0;

int gcd(int a, int b) {
    if (b == 0) return a;
    a%=b;
    return gcd(b,a);
}

int main() {
    cin >> K;
    for (int i = 1; i <= K; ++i)
        for (int j = 1; j <= K; ++j)
            for (int k = 1; k <= K; ++k) {
                vector<int> v = {i,j,k};
                sort(ALL(v));
                res += gcd(v[2], gcd(v[1], v[0]));
            }
    cout << res << endl;
}
