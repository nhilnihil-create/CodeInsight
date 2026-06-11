#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    int l[n];
    rep(i, n) { cin >> l[i]; }

    int d[n + 1] = {0};
    int count = 1;
    for(int i = 1; i < n + 1; ++i) {
        d[i] = d[i - 1] + l[i - 1];
        if(d[i] <= x)
            count++;
    }

    cout << count << endl;
}