#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

//1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
int main() {
    int n, m;
    cin >> n >> m;
    int c = (n+1) / 2;
    vector<P> ans;
    int i = c / 2;
    int j = i + 1;
    while (i > 0) {
        ans.push_back(P(i, j));
        --i; ++j;
    }
    i = c + c / 2;
    rep(j, m/2) {
        ans.push_back(P(i-j-1, j+i+1));
    }
    rep(i, m) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}