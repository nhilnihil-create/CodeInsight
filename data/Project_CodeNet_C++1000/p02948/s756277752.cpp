#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define pq priority_queue

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> jobs(n);
    pq<int, vector<int>, greater<int>> taken_jobs; //min pq
    for (int i = 0; i < n; i++) {
        int d, r;
        cin >> d >> r;
        jobs[i] = make_pair(d, r);
    }
    sort(jobs.begin(), jobs.end(), greater<pair<int, int>>()); //sorts by days taken
    int rew = 0;
    for (int i = 0; i < n; i++) {
        int j_rew = jobs[i].second;
        if (taken_jobs.size() + jobs[i].first <= m) {
            rew += j_rew;
            taken_jobs.push(j_rew);
        }
        else if (!taken_jobs.empty() && j_rew > taken_jobs.top()) {
            //Note: will always fit, as it is sorted by days (descending),
            //and if taken_jobs is not empty, it will always be able to fit.
            rew -= taken_jobs.top();
            rew += j_rew;
            taken_jobs.pop();
            taken_jobs.push(j_rew);
        }
    }
    std::cout << rew;
}