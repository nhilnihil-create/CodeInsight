// @author: arch_

#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int h, w;
    vector<array<int, 2>> a;
    while (cin >> h >> w, h | w) {
        array<int, 2> i{h, w};
        a.emplace_back(i);
    }
    for (auto&& i : a) {
        for (int y = 0; y < i[0]; y++) {
            for (int x = 0; x < i[1]; x++)
                cout << "#";
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}