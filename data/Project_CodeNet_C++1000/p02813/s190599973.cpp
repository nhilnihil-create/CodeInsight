#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define loop(i, a, n) for(int i = (a); i < (n); i++)
#define all(x) x.begin(), x.end()
#ifdef _DEBUG
#define dd(x) cout << #x << " : " << x << endl
#define sorn(i, n) char((i == n-1)?'\n':' ')
#else
#define dd(x)
#endif
using namespace std;
using ll = int64_t;

bool check(int n, int p[], vector<int> np) {
    rep(i, n) {
        if(p[i] != np[i]) {
            return false;
        }
    }
    return true;
}

int main(){
    int n; cin >> n;
    int p[n], q[n];
    rep(i, n) cin >> p[i];
    rep(i, n) cin >> q[i];

    vector<int> np; rep(i, n) np.push_back(i+1);

    int a = 0, b = 0;
    bool aflag = true, bflag = true;
    int cnt = 0;
    do {
        if(check(n, p, np)) {
            a = cnt;
        }
        if(check(n, q, np)) {
            b = cnt;
        }
        cnt++;
    } while(next_permutation(all(np)));

    cout << abs(a-b) << endl;

    return 0;
}
