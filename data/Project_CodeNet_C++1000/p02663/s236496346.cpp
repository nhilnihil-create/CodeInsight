#include <bits/stdc++.h>
using namespace std;
using ll  = long long;
using vl  = vector<ll>;
using vvl = vector<vl>;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define per(i,n) for(int i = (n)-1; i >= 0; --i)
#define rng(i,a,b) for(int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main() {
    int h1, m1, h2, m2, k;
    cin >> h1 >> m1 >> h2 >> m2 >> k;
    m1 += h1 * 60;
    m2 += h2 * 60;
    cout << (m2 - m1 - k) << endl;
    return 0;
}
