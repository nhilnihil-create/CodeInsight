#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define arep(x,n) for (int x: n)
using namespace std;

const double PI = acos(-1);

int main()
{
    int n,m; cin >> n >> m;
    vector<int> h(n); rep(i,n) cin >> h.at(i);
    vector<vector<int>> ab(m,vector<int>(2)); 
    rep(i, m) cin >> ab.at(i).at(0) >> ab.at(i).at(1);

    vector<int> tmp(n);

    rep(i, m) {
        int subA = ab.at(i).at(0), subB = ab.at(i).at(1);
        if(h.at(subA - 1) < h.at(subB - 1)) {
            tmp.at(subA - 1) = 1;
        } else if (h.at(subA - 1) > h.at(subB - 1)) {
            tmp.at(subB - 1) = 1;
        } else {
            tmp.at(subA - 1) = 1;
            tmp.at(subB - 1) = 1;
        }
    }

    int cnt = 0;
    rep(i, n) cnt += tmp.at(i);
    cout << n - cnt << endl;
}

