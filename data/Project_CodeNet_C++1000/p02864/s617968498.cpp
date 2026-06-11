#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cstring>
using namespace std;
const int BUF = 305;
const long long INF = 1LL<<62;

int nCol, nCut;
int col2height[BUF];

void read() {
    cin >> nCol >> nCut;
    for (int i = 0; i < nCol; ++i) {
        cin >> col2height[i];
    }
}


long long rec(int idx, int remainCut, int heightId, long long dp[BUF][BUF][BUF],
              vector<int> &id2height, map<int, int> &height2id) {
    
    if (idx == nCol) return 0;
    
    long long &ret = dp[idx][remainCut][heightId];
    if (ret != -1) return ret;

    ret = INF;

    // cut
    if (remainCut > 0) {
        ret = min(ret, rec(idx + 1, remainCut - 1, heightId, dp, id2height, height2id));
    }

    // not cut
    ret = min(ret, rec(idx + 1, remainCut, height2id[col2height[idx]], dp, id2height, height2id) +
              + max(0, col2height[idx] - id2height[heightId]));
    
    return ret;
}


void work() {
    vector<int> id2height;
    for (int i = 0; i < nCol; ++i) {
        id2height.push_back(col2height[i]);
    }
    id2height.push_back(0);
    sort(id2height.begin(), id2height.end());
    id2height.erase(unique(id2height.begin(), id2height.end()), id2height.end());

    map<int, int> height2id;
    for (int i = 0; i < id2height.size(); ++i) {
        height2id[id2height[i]] = i;
    }
    
    static long long dp[BUF][BUF][BUF];
    memset(dp, -1, sizeof(dp));

    cout << rec(0, nCut, 0, dp, id2height, height2id) << endl;
}


int main() {
    read();
    work();
    return 0;
}
