#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
using namespace std;
#define LL long long

void _131() {
    int n;
    cin >> n;
    int tmp_a, tmp_b;
    vector<pair<int, int> > data;
    for (int i = 0; i < n; ++i) {
        cin >> tmp_a >> tmp_b;
        data.push_back(make_pair(tmp_b, tmp_a));
    }

    sort(data.begin(), data.end());

    LL sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += data[i].second;
        // cout << sum << " " << data[i].first << endl;
        if (sum > data[i].first) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}

int main()
{
    _131();
    return 0;
}

