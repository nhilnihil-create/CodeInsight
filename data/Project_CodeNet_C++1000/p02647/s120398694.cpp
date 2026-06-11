#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define exrep(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) cout << x << endl
#define exout(x) printf("%.10f\n", x)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define re0 return 0
const ll mod = 1000000007;
const ll INF = 1e16;
const double pi = acos(-1);

int main() {
    ll n, k;
    cin >> n >> k;

    vl a(n);
    rep(i, n) {
        cin >> a[i];
    }
    
    rep(loop, k) {
        bool flag = true;  // 全ての電球の強さがnならtrue
        rep(i, n) {
            if(a[i] < n) {
                flag = false;
            }
        }
        if(flag) {
            break;
        }
        vl b(n+1);  // b[i] : 座標iを照らす電球の個数
        rep(i, n) {
            b[max(0LL, i - a[i])]++;
            b[min(n, i + a[i] + 1)]--;
        }
        rep(i, n) {
            b[i+1] += b[i]; 
        }
        rep(i, n) {
            a[i] = b[i];
        }
    }

    rep(i, n) {
        cout << a[i];
        if(i < n-1) {
            cout << " ";
        }
    }

    cout << endl;
    re0;
}