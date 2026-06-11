#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
bool b_asc(pair<int, int> l, pair<int, int> r) {
    if(l.second != r.second) {
        return l.second < r.second;
    } else {
        return l.first < r.first;
    }
}

int main () {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), b_asc);

    ll sum = 0;
    bool f = true;
    for (int i = 0; i < n; i++)
    {
        sum += a[i].first;

        if(sum > a[i].second) {
            f = false;
        }
    }

    string ans = f ? "Yes" : "No";

    cout << ans << "\n";

}