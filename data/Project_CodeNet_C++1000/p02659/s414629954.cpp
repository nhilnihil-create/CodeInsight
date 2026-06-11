#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG 
#define rep(i, n) for (int i = 0; i < n; i++)
#define reps(i, s, n) for (int i = s; i < n; i++)
#define all(v) v.begin(), v.end() // sort(all(array))
#define INF 1000000000
#define mod 1000000007
#define EPS 0.001
using namespace std;
using ll = long long;
using vi = vector<int>; //vi array(要素数, 初期値)
using pll = pair<ll, ll>;
using pii = pair<int, int>;
using vc = vector<char>;
using vs = vector<string>;
using vb = vector<bool>;
using vvi = vector<vi>; //vvi table(行数, vi(列数, 初期値))
using vvc = vector<vc>;
using vvs = vector<vs>;
using vvb = vector<vb>;

int main() {
    ll a; cin >> a;
    string b; cin >> b;
    ll b100 = (b[0] - '0') * 100 + (b[2] - '0') * 10 + (b[3] - '0');
    cout << a * b100 / 100 << endl;
}

