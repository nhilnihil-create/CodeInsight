#include <iostream>
#include <queue>
#include <string>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

struct Job {
    string name;
    int time;
};
Job job[100005];
int main() {
    int n, q;
    cin >> n >> q;
    rep(i, n) cin >> job[i].name >> job[i].time;
    queue<Job> que;
    rep(i, n) que.push(job[i]);
    int total = 0;
    while (!que.empty()) {
        Job t = que.front();
        que.pop();
        total += min(t.time, q);
        t.time -= q;
        if (t.time > 0) {
            que.push(t);
        } else {
            cout << t.name << " " << total << endl;
        }
    }
    return 0;
}