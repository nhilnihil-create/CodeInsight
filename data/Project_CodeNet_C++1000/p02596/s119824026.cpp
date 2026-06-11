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
const int INF = 1e18;

signed main() {
    int K;
    cin >> K;
    if(K==2 || K==5) {
        cout << -1 << endl;
        return 0;
    }

    int res = -1;
    int t = 0;
    rep(i, 1000000) {
        t += 7;
        if(t%K==0) {
            res = i+1;
            break;
        }
        t = (t*10)%K;
    }

    cout << res << endl;

    return 0;
}