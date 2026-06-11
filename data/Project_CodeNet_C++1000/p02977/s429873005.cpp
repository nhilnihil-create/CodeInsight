#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>
using namespace std;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> p2;

    for (int i = 0; pow(2, i) < 1e6; i++) {
        if (n == pow(2, i)) {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    vector<pair<int, int> > ans;
    for (int i = 0; i < (n - 1) / 2; i++) {
        ans.emplace_back(n + (i + 1) * 2, (i + 1) * 2 + 1);
        ans.emplace_back(1, (i + 1) * 2 + 1);
        ans.emplace_back(1, (i + 1) * 2);
        ans.emplace_back((i + 1) * 2, n + (i + 1) * 2 + 1);
    }

    if (n % 2 == 1) ans.emplace_back(n + 1, 2 * n);
    else {
        ans.emplace_back(n + 3, n + 1);
        /* ans.emplace_back(n - 1, n);
        ans.emplace_back(2, 2 * n);*/

        for (int i = 2; i <= n; i++) {
            if (((n - 2) ^ i) == n) {
                ans.emplace_back(n - 1, n);
                ans.emplace_back(i, 2 * n);
                break;
            }
        }
    }



    for (int i = 0; i < ans.size(); i++) 
    cout << ans[i].first << " " << ans[i].second << endl;
    
    //cout << (10 ^ 2) << endl;
}

/*
g++ -std=c++14 agc035/c.cpp
 */