#include <iostream>
#include <string>
#include <vector>

#define fastIO (cin.tie(0), cout.tie(0), ios::sync_with_stdio(false))
#define rep(i, n) for (int i = 0; i < (n); ++i)

using lint = long int;
using llint = long long int;
using namespace std;

int main() {
    fastIO;

    int n;
    cin >> n;
    vector<int> takoyaki(n);
    rep(i, n) cin >> takoyaki.at(i);

    int total = 0;
    for (size_t i = 0; i < takoyaki.size() - 1; i++) {
        for (size_t j = i + 1; j < takoyaki.size(); j++) {
            total += takoyaki.at(i) * takoyaki.at(j);
        }
    }
    cout << total << endl;
}

