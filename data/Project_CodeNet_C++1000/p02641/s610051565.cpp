#include <iostream>

using namespace std;
int x, n;
pair<int, int> min_ans = {999, -1};
bool exclude[102];

int main() {
    int a;
    cin >> x >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        exclude[a] = true;
    }

    // 1 <= a <= 100
    // therefore, 0 <= ans.second <= 101
    for (int i = 0; i <= 101; ++i) {
        if (exclude[i]) continue;
        pair<int, int> cur = {abs(x - i), i};
        min_ans = min(min_ans, cur);
    }
    cout << min_ans.second << endl;
    return 0;

    int i = 0;
    while (true) {
        if (!exclude[x - i]) {
            cout << x - i << endl;
            return 0;
        }
        if (!exclude[x + i]) {
            cout << x + i << endl;
            return 0;
        }
        i++;
    }
}
