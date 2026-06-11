#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
#define int int64
#define rep(i, n) for(int i=0; i<n; i++)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define SORT(x) sort(x.begin(), x.end())
#define GSORT(x) sort(x.begin(), x.end(), greater<int>())
#define mk make_pair
#define fi first
#define se second
#define pb push_back
#define ALL(x) x.begin(), x.end()
#define V(T) vector<T>
typedef pair<int, int> P;
typedef pair<P, P> PP;
typedef vector<int> vi;
typedef vector<vi> vvi;
int max(int a, int b) {if(b>a) return b; else return a;}
int min(int a, int b) {if(b<a) return b; else return a;}

signed main() {
    int N, D, A;
    cin >> N >> D >> A;
    V(P) XH(N);
    rep(i, N) {
        int x, h;
        cin >> x >> h;
        x--;
        XH[i] = P(x, h);
    }
    SORT(XH);

    queue<P> q;
    int cnt = 0, res = 0;
    rep(i, N) {
        int x = XH[i].fi, h = XH[i].se;
        while(!q.empty()) {
            P p = q.front();
            if(x>p.fi) {
                cnt -= p.se;
                q.pop();
            } else break;
        }
        int b = A*cnt;
        if(h>b) {
            int t = ((h-b)/A) + ((h-b)%A ? 1 : 0);
            res += t;
            q.push(P(x+2*D, t));
            cnt += t;
        }
    }

    cout << res << endl;
 
    return 0;
}