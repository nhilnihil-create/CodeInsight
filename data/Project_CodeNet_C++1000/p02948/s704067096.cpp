#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

#include <limits.h>

using namespace std;

typedef long long ll;

template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

// {days, rewards}
vector<pair<int, int>> works;

int main(void) {
    int N, M;
    cin >> N >> M;

    works.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        works[i] = {a, b};
    }
    sort(works.begin(), works.end());

    int ind_works = 0;
    priority_queue<int> que;
    ll ans = 0;

    for (int req_days = 1; req_days <= M; req_days++) {
        while (ind_works < N && works[ind_works].first <= req_days) {
            que.push(works[ind_works].second);
            ind_works++;
        }

        if (!que.empty()) {
            int work = que.top();
            // printf("req_days: %d, work: %d\n", req_days, work);
            que.pop();
            ans += work;
        }
    }

    cout << ans << endl;

    return 0;
}
