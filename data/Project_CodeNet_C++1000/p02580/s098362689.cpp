#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, m;
    cin >> h >> w >> m;
    int it, jt;
    set<pair<int, int>> obj;
    vector<int> ci(h), cj(w);
    rep(i, m) {
        cin >> it >> jt;
        it--; jt--;
        obj.emplace(make_pair(it, jt));
        ci[it]++;
        cj[jt]++;
    }
    int mi = *max_element(ci.begin(), ci.end());
    int mj = *max_element(cj.begin(), cj.end());
    vector<int> mei, mej;
    rep(i, h) if(ci[i] == mi) mei.emplace_back(i);
    rep(j, w) if(cj[j] == mj) mej.emplace_back(j);
    
    int cnt = obj.size();
    for(int i: mei) {
        for(int j: mej) {
            if(obj.find(make_pair(i, j)) == obj.end()) {
                printf("%d\n", mi + mj);
                return 0;
            } else if(cnt == 0) break;
            cnt--;
        }
    }
    printf("%d\n", mi + mj - 1);

    return 0;
}