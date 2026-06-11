#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> job(N);
    rep(i, N) {
        int A, B;
        cin >> A >> B;
        job[i] = {A, B};
    }
    
    sort(job.begin(), job.end());
    int ans = 0, cnt = 0;
    priority_queue<int> pq;
    REP(i, M + 1) {
        while (cnt < N) {
            if (job[cnt].first == i) {
                pq.push(job[cnt].second);
                ++cnt;
            } else {
                break;
            }
        }
        if (pq.size()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
