#include <iostream>
#include <set>
using namespace std;

int main() {
    while (true) {
        int n, m;
        cin >> n >> m;
        if ((n | m) == 0) {
            break;
        }
        int sum[2] = {};
        set<int> taro, hanako;
        for (int i = 0; i < n; i++) {
            int s;
            cin >> s;
            taro.insert(s);
            sum[0] += s;
        }
        for (int i = 0; i < m; i++) {
            int s;
            cin >> s;
            hanako.insert(s);
            sum[1] += s;
        }
        for (set<int>::iterator itT = taro.begin(); itT != taro.end(); itT++) {
            for (set<int>::iterator itH = hanako.begin(); itH != hanako.end(); itH++) {
                if (sum[0] - *itT + *itH == sum[1] - *itH + *itT) {
                    cout << *itT << " " << *itH << endl;
                    goto end;
                }
            }
        }
        cout << -1 << endl;
    end:;
    }
}