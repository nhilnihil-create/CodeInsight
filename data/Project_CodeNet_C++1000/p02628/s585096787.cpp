#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    vector<long long> list(1);
    long long n, k, current;
    cin >> n >> k;
    cin >> list[0];
    for (long long i = 1; i < n; i++) {
        cin >> current;
        list.emplace_back(current);
    }
    sort(list.begin(), list.end());
    long long sum = 0;
    list.resize(k);
    list.shrink_to_fit();
    for (auto x : list) {
        sum += x;
    }
    cout << sum << '\n';
}