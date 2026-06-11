#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n, a, b;
long long ct;
vector <pair<int, int>> v;
bool compare_by_b(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}
int main() {
    cin >> n;
    ct = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    } 
    ct = 0;
    sort(v.begin(), v.end(), compare_by_b);
    for (int i = 0; i < n; i++) {
        ct += v[i].first;
        if (ct > v[i].second) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}