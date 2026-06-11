#include<bits/stdc++.h>
using namespace std;

const int max_n=3e5+10;
int row[max_n],col[max_n];
vector<int>rr,cc;
set<pair<int,int>>sp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int max_r = 0, max_col = 0;
    for (int i = 1; i <= k; ++i) {
        int a, b;
        cin >> a >> b;
        sp.insert(make_pair(a, b));
        row[a]++;
        col[b]++;
        if (max_r < row[a]) {
            max_r = row[a];
            rr.clear();
            rr.push_back(a);
        } else if (max_r == row[a]) {
            rr.push_back(a);
        }
        if (max_col < col[b]) {
            max_col = col[b];
            cc.clear();
            cc.push_back(b);
        } else if (max_col == col[b]) {
            cc.push_back(b);
        }
    }
    for (auto i:rr) {
        for (auto j:cc) {
            if (sp.count(make_pair(i, j)))
                continue;
            else {
                cout << max_col + max_r;
                return 0;
            }
        }
    }
    cout<<max_col + max_r-1;
    return 0;
}