#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;
#define PI  3.14159265358979323846

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
ll N, M, Q;
ll ans = 0;
vector<ll>a, b, c, d;

void dfs(vector<ll> A) {
    if (A.size()==N) {
        ll tmpMax = 0;
        rep(i,Q) {
            if (A[b[i]-1] - A[a[i]-1] == c[i])tmpMax += d[i];
        }
        ans = max(ans,tmpMax);
        return;
    }
    A.push_back(A.back());
    while (A.back()<=M) {
        dfs(A);
        A.back()++;
    }
}

int main() {
    cin >> N >> M >> Q;
    a = b = c = d = vector<ll>(Q);
    rep(i,Q) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }
    dfs(vector<ll>(1,1));
    cout << ans << endl;
    return 0;
}