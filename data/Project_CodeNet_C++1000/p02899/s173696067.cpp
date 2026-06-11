#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using P = pair<int, int>;
#define LARGE 1000000007

int main() {
    int n;
    cin >> n;
    vector<P> p(n);

    rep(i, n) {
        int a;
        cin >> a;
        p[i] = make_pair(a, i+1);
    }
    sort(p.begin(), p.end());
    rep(i, n) {
        cout << p[i].second << ' ';
    }
    cout << endl;

	return 0;
}