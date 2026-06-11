#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int myposition(const pair<long long int, long long int>& p) {
    long long int x = p.first, y = p.second;
    if (x > 0 && y >= 0) {
        return 1;
        }
        if (x <= 0 && y > 0) {
            return 2;
        }
        if (x < 0 && y <= 0) {
            return 3;
        }
        if (x >= 0 && y < 0) {
            return 4;
        }
        return 0;
}

bool mycompare(const pair<long long int, long long int>& p1,
    const pair<long long int, long long int>& p2) {
    return 1.0 * pow(p1.second, 2) / (pow(p1.first, 2) + pow(p1.second, 2)) < 1.0 * pow(p2.second, 2) / (pow(p2.first, 2) + pow(p2.second, 2));
}

int main() {
    int n;
    cin >> n;
    vector<pair<long long int, long long int>> vp1, vp2, vp3, vp4, vp;
    long long int x, y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x > 0 && y >= 0) {
            vp1.emplace_back(x, y);
        }
        if (x <= 0 && y > 0) {
            vp2.emplace_back(x, y);
        }
        if (x < 0 && y <= 0) {
            vp3.emplace_back(x, y);
        }
        if (x >= 0 && y < 0) {
            vp4.emplace_back(x, y);
        }
    }
    sort(vp1.begin(), vp1.end(), mycompare);
    sort(vp2.begin(), vp2.end(), mycompare);
    reverse(vp2.begin(), vp2.end());
    sort(vp3.begin(), vp3.end(), mycompare);
    sort(vp4.begin(), vp4.end(), mycompare);
    reverse(vp4.begin(), vp4.end());
    vp.reserve(vp1.size() + vp2.size() + vp3.size() + vp4.size());
    vp.insert(vp.end(), vp1.begin(), vp1.end());
    vp.insert(vp.end(), vp2.begin(), vp2.end());
    vp.insert(vp.end(), vp3.begin(), vp3.end());
    vp.insert(vp.end(), vp4.begin(), vp4.end());
    double res = 0;
    n = vp.size();
    for (int i = 0; i < n; i++) {
        int pos1 = myposition(vp[i]);
        int next_pos1 = (pos1 + 1 == 5 ? 1 : pos1 + 1);
        int next_pos2 = (pos1 + 2 > 4 ? pos1 + 2 - 4 : pos1 + 2);
        int index = (i + 1) % n;
        x = vp[i].first, y = vp[i].second;
        
        res = max(res, pow(x * x + y * y, 0.5));
        while (index != i) {
            int pos2 = myposition(vp[index]);
            long long int c = vp[index].first * vp[i].first + vp[index].second * vp[i].second;
            if ((pos2 == next_pos1) || (pos2 == pos1 && c >= 0) || (pos2 == next_pos2 && c <= 0)) {
                x += vp[index].first;
                y += vp[index].second;
                res = max(res, pow(x * x + y * y, 0.5));
            } else {
                break;
            }
            index = (index + 1) % n;
        }
        res = max(res, pow(x * x + y * y, 0.5));
    }
    cout << setprecision(30) << res << endl;
}







