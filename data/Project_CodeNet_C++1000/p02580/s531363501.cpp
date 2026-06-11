#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;


int main(){
    int h, w, m;
    cin >> h >> w >> m;

    set<pii> bomb;
    vector<int> row_num(h, 0), col_num(w, 0);
    int h_, w_;
    for (int i = 0; i < m; ++i) {
        cin >> h_ >> w_;
        h_--; w_--;
        bomb.insert(pii(h_, w_));
        row_num[h_]++;
        col_num[w_]++;
    }

    int hmax = 0;
    int wmax = 0;
    for (int i = 0; i < h; ++i) {
        hmax = max(hmax, row_num[i]);        
    }
    for (int i = 0; i < w; ++i) {
        wmax = max(wmax, col_num[i]);
    }
    vector<int> row_max, col_max;
    for (int i = 0; i < h; ++i) {
        if (row_num[i] == hmax) row_max.push_back(i);
    }
    for (int i = 0; i < w; ++i) {
        if (col_num[i] == wmax) col_max.push_back(i);
    }
    
    for (int i = 0; i < row_max.size(); ++i) {
        for (int j = 0; j < col_max.size(); ++j) {
            if (bomb.count(pii(row_max[i], col_max[j])) == 0){
                cout << hmax + wmax << endl;
                return 0;
            }
        }
    }
    cout << hmax + wmax - 1 << endl;
}