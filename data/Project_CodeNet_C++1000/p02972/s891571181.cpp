//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; ++i)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = int64_t;
using P = pair<int, int>;
using vs = vector<string>;
using vi = vector<int>;
using vvi = vector<vi>;
const int INF = 100010001;
const ll LINF = (ll)INF*INF*10;

int main() {
    int n;
    cin >> n;
    vi a(n+1);
    rep(i, n) {
        cin >> a[i+1];
    }
    int cou = 0;
    for(int i=n; i>0; --i) {
        int i_ = i;
        i_ += i;
        int sum = 0;
        while(i_ <= n) {
            sum += a[i_];
            i_ += i;
        }
        if((sum & 1) != a[i]) {
            a[i] = 1;
            cou++;
        } else {
            a[i] = 0;
        }
    }

    cout << cou << endl;

    rep(i, n+1) {
        if(a[i]) {
            cout << i << ' ';
        }
    }
    cout << endl;
}