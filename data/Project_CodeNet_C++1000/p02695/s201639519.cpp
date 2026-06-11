#include <iostream>
#include <cmath>
#include <algorithm>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);++i)
#define REP(i,n) for (int i=0;i<=(n);++i)
#define all(x) (x).begin(), (x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

int n, m, q;
vector<int> a, b, c, d;

int score(const vector<int> &A) {
    int ans = 0;
    for(int i = 0; i < q; ++i) {
        if(A[b[i]] - A[a[i]] == c[i]) {
            ans += d[i];
        }
    }
    return ans;
}

int dfs(vector<int> &A) {
    if(A.size() == n) {
        return score(A);
    }
    int ans = 0;
    int prev = (A.empty() ? 0 : A.back());
    for(int i = prev; i < m; ++i) {
        A.push_back(i);
        ans = max(ans, dfs(A));
        A.pop_back();
    }
    return ans;
}



int main() {
    cin >> n >> m >> q;
    a.resize(q);
    b.resize(q); 
    c.resize(q);
    d.resize(q);

    for(int i = 0; i < q; ++i) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        --a[i];
        --b[i];
    }
    vector<int> A;
    cout << dfs(A) << endl;

}