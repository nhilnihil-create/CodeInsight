#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);
#define chmin(x,y) x = min(x,y);
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};
const int INF = 1001001001;



int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> id(n+1, -1);
    vector<int> s;
    int len = 0;
    int x = 1;
    while (id[x] == -1) {
        s.push_back(x);
        id[x] = len;
        len++;
        x = a[x-1];
    }

    int c = len - id[x];
    if (k < len) {
        cout << s[k] << endl;
        return 0;
    }
    else {
        k -= len;
        k %= c;
        cout << s[id[x]+k] << endl;
    }
    return 0;
}