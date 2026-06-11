#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#include<deque>
#include<map>
#include<bitset>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0;i < (n);i++)
#define repr(i, n) for(int i = (n);i >= 0;i--)
#define repf(i, m, n) for(int i = (m);i < (n);i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1;} return 0;}
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
//////////////////////////////////////////////////


int main() {
    int n, k; cin >> n >> k;
    if (k > (n-2)*(n-1)/2) {
        cout << -1 << endl;
        return 0;
    }
    vector<vector<int>> g(n, vector<int>(n,1));
    int cnt = 0;
    rep(i,n-1) repf(j,i+1,n-1) {
        if (cnt >= k) {
            break;
        }
        cnt++;
        g[i][j] = g[j][i] = 0;
    }

    cout << n*(n-1)/2-cnt << endl;
    rep(i,n) repf(j,i+1,n) {
        if (g[i][j]) {
            cout << i+1 << " " << j+1 << endl;
        }
    }
    return 0;
}