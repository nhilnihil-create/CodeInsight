#include <bits/stdc++.h>
     
using namespace std;
     
int main() {
    int n;
    cin >> n;
    vector<int> bricks(n);
    for (int i = 0; i < n; i++) {
        cin >> bricks[i];
    }
    int next_no = 1;
    for (int i = 0; i < n; i++) {
        if (bricks[i] == next_no) {
            next_no++;
        }
    }
    if (next_no == 1) {
        cout << -1;
    } else {
        cout << n - next_no + 1;
    }
}