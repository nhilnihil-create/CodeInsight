#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i != n; i++) {
        int j;
        cin >> j;
        v.push_back(-j);
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for (int i = 0; i != n / 2; i++)ans += v[i];
    for (int i = 0; i != (n - 1) / 2; i++)ans += v[i + 1];
    cout << -ans;
    return 0;
}