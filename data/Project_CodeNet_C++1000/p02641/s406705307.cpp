#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    if (n == 0) {
        cout << x << endl;
    } else {
        sort(p.begin(), p.end());
        int idx = 0;
        vector<int> a_list;
        for (int i = 0 ; i < 105; i++) {
            if (p[idx] == i) {
                if (idx+1 < p.size()) {
                    idx++;
                }
            } else {
                a_list.push_back(i);
            }
        }
        int min = 1000;
        for (int i = 0; i < a_list.size(); i++) {
            int dist = abs(x - a_list[i]);
            if (dist < min) min = dist;
            else {
                cout << a_list[i-1] << endl;
                break;
            }
        }
    }

    return 0;
}