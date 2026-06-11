#include <bits/stdc++.h>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define ALL(a) a.begin(), a.end()
#define MOD 1000000007
using namespace std;
typedef long long ll;

int main() {
    int N; cin >> N;
    
    vector<int> positive, negative;
    REP(i, 0, N) {
        int a; cin >> a;
        if (a < 0) negative.push_back(a);
        else positive.push_back(a);
    }

    sort(ALL(positive), greater<int>());
    sort(ALL(negative));
    if (positive.size() == 0) {
        positive.push_back(negative.back());
        negative.pop_back();
    }
    if(negative.size() == 0) {
        negative.push_back(positive.back());
        positive.pop_back();
    }

    vector<pair<int, int>> ans; int cur = negative[0];
    REP(i, 0, positive.size() - 1) {
        ans.push_back({cur, positive[i]});
        cur -= positive[i];
    }

    ans.push_back({positive.back(), cur});
    cur = positive.back() - cur;

    REP(i, 1, negative.size()) {
        ans.push_back({cur, negative[i]});
        cur -= negative[i];
    }
    
    cout << cur << endl;
    for (auto a : ans) cout << a.first << " " << a.second << endl;

    return 0;
}