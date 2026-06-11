#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }

bitset<100010> A[62];
int v[62];

int gauss_elimination(int n, int m){
    int r = 0;
    REP(j,m){
        FOR(i,r,n-1){
            if (A[i][j]){
                swap(A[r], A[i]);
                swap(v[r], v[i]);
                break;
            }
        }
        if (A[r][j] == 0) continue;
        FOR(i,r+1,n-1){
            int k = A[i][j];
            if (k) A[i] ^= A[r];
            if (k) v[i] ^= v[r];
            // cout << "here" << endl;
            // REP(i,n){
            //     REP(j,m) cout << A[i][j] << " ";
            //     cout << endl;
            // }
        }
        r++;
        if (r == n) break;
    }
    return r;
}

int main() {
    int n;
    cin >> n;
    VL a(n);
    ll x = 0;
    REP(i,n){
        a[i] = lin();
        x ^= a[i];
    }
    int m = 62;
    ll y = 0;
    REP(bb,m){
        int b = m - bb - 1;
        bool f = true;
        int d = 0;
        FOR(c,b,m-1){
            if (c != b && ((y >> c) & 1) == 0) continue;
            int cnt = 0;
            REP(i,n){
                A[d][i] = ((a[i] >> c) & 1);
                cnt += A[d][i];
            }
            if (cnt % 2){
                f = false;
            }
            if (!f) break;
            v[d] = 1;
            d++;
        }
        if (!f) continue;
        // cout << endl;
        // REP(i,A.size()){
        //     for (int x : A[i]) cout << x;
        //     cout << endl;
        // }
        int r = gauss_elimination(d, n);
        int s = 0;
        REP(i,d) if (v[i]) s = i + 1;
        // cout << b << " " << r << " " << s << " " << f << endl;
        if (f && r >= s){
            y |= (1LL << b);
        }
    }
    cout << x + 2 * y << endl;

    return 0;
}
