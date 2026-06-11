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

// {days, reward}
vector<pair<int, int>> jobs;

int main(void) {
    int N, M;
    cin >> N >> M;

    jobs.resize(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        jobs[i] = {a, b};
    }

    sort(jobs.begin(), jobs.end());

    priority_queue<int> que;
    int ans = 0;
    int i_jobs = 0;
    for (int day = 1; day <= M; day++) {
        while (i_jobs < N && jobs[i_jobs].first <= day) {
            que.push(jobs[i_jobs].second);
            i_jobs++;
        }

        if (!que.empty()) {
            auto reward = que.top();
            que.pop();
            ans += reward;
        }
    }

    cout << ans << endl;

    return 0;
}
