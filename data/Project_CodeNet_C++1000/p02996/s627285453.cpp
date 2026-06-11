#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;

int main() {
    int n;
    cin >> n;
    vii jobs;
    jobs.reserve(n);
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        jobs.push_back({b, a});
    }
    sort(jobs.begin(), jobs.end());
    int time = 0;
    bool possible = true;
    for (const auto& pair : jobs) {
        time += pair.second;
        if (time > pair.first) {
            cout << "No\n"; 
            possible = false;
            break;
        }
    }
    if (possible)
        cout << "Yes\n";
}