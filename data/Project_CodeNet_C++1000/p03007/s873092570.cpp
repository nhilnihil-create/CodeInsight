#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> plus, minus;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a > 0)plus.push_back(a);
        else minus.push_back(a);
    }
    sort(plus.begin(), plus.end()), sort(minus.begin(), minus.end());

    int ret = 0;
    vector<vector<int>> ope;
    if (plus.size() > 0 && minus.size() > 0) {
        for (int i = 1; i < minus.size(); i++) {
            ope.push_back({plus.front(), minus[i]});
            plus.front() -= minus[i];
        }
        for (int i = 1; i < plus.size(); i++) {
            ope.push_back({minus.front(), plus[i]});
            minus.front() -= plus[i];
        }
        ope.push_back({plus.front(), minus.front()});
        ret = plus.front() - minus.front();
    } else if (plus.size() > 0) {
        for (int i = 2; i < plus.size(); i++) {
            ope.push_back({plus.front(), plus[i]});
            plus.front() -= plus[i];
        }
        ope.push_back({plus[1], plus.front()});
        ret = plus[1] - plus.front();
    } else {
        for (int i = 0; i < minus.size() - 1; i++) {
            ope.push_back({minus.back(), minus[i]});
            minus.back() -= minus[i];
        }
        ret = minus.back();
    }

    cout << ret << endl;
    for (auto x:ope)cout << x[0] << " " << x[1] << endl;
    return 0;
}