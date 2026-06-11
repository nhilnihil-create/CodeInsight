#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> monsters(n + 1);
    for (int i = 0; i < n + 1; i++) {
        cin >> monsters[i];
    }
    int last = monsters[0];
    ll killed = 0;
    for (int i = 1; i < n + 1; i++) {
        int kill;
        cin >> kill;
        int new_last = monsters[i];
        if (last < kill) {
            if (new_last + last > kill) {
                killed += kill;
                new_last -= kill - last;
            }
            else {
                killed += (new_last + last);
                new_last = 0;
            }
        }
        else {
            killed += kill;
        }
        last = new_last;
    }
    cout << killed;
}