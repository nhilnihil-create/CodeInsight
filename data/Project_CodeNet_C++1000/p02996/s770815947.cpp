#include <bits/stdc++.h>
using namespace std;

struct task {
    long long int duration;
    long long int deadline;

    bool operator<(const task& another) const {
        return deadline < another.deadline;
    }
};

int main() {
    int N;
    cin >> N;

    vector<task> tasks(N);
    for (int i = 0; i < N; i++) {
        cin >> tasks[i].duration >> tasks[i].deadline;
    }
    sort(tasks.begin(), tasks.end());

    long long int now = 0;

    for (int i = 0; i < N; i++) {
        now += tasks[i].duration;
        // cout << tasks[i].duration << " " << tasks[i].deadline << endl;
        if (tasks[i].deadline < now) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
