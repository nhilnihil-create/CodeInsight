#include <vector>
#include <queue>
#include <iostream>
#include <set>
#include <algorithm>
#define ii pair<int, int>
#define iii pair<ii, int>
#define pq priority_queue

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n; //note: n always odd
    vector<int> dams(n);
    for (int i = 0; i < n; i++) {
        cin >> dams[i];
    }
    int last_sum = 0;
    //compute mt 1
    int sgn = 1;
    for (int i = 0; i < n; i++) {
        last_sum += dams[i] * sgn;
        sgn *= -1;
    }
    cout << last_sum << '\n';
    for (int i = 0; i < n - 1; i++) {
        cout << dams[i] * 2 - last_sum << '\n';
        last_sum = dams[i] * 2 - last_sum;
    }
}