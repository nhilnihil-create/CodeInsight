//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using ld = long double;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n, a, b;
    cin >> n >> a >> b;
    if((b-a)&1) {
        if(n-b > a-1) {
            a = -a+1;
        } else {
            b = n+n-b+1;
        }
    }
    cout << (b-a)/2 << endl;
}