#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int INF = 1001001001;

int main() {
    int n, k, c;
    cin >> n >> k >> c;
    string s;
    cin >> s;
    vector<int> A(n+1, 0), B(n+1, 0);
    int p = -INF;
    rep(i, n) {
        A[i+1] = A[i];
        if (s[i] == 'o' && p+c < i) {
            p = i;
            A[i+1]++;
        }
    }
    p = INF;
    for (int i = n-1; i >= 1; --i) {
        B[i-1] = B[i];
        if (s[i] == 'o' && p-c > i) {
            p = i;
            B[i-1]++;
        }
    }
    vector<int> ans;
    auto r_search = [&](int a) {
        int l = -1;
        int r = n;
        while (r-l > 1) {
            int m = (l+r) / 2;
            if (B[m] >= a) l = m;
            else r = m;
        }
        return l; 
    };
    rep(i, n) {
        if (s[i] == 'x') continue;
        int t = A[i] + B[i];
        int l = lower_bound(A.begin(), A.end(), A[i]) - A.begin();
        int r = r_search(B[i]);
        if (A[i] == 0) l = -INF;
        if (B[i] == 0) r = INF;
        if (c >= r-l+2) t--;
        if (t < k) {
            ans.push_back(i+1);
        }
    }
    for (int x: ans) {
        cout << x << endl;
    }
    return 0;
}