#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> a[100007];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1, [](auto a, auto b) -> bool { return a.first < b.first; });
    for (int i = 1; i <= n; i++) {
        cout << a[i].second << ' ';
    }
    cout << endl;
    return 0;
}
