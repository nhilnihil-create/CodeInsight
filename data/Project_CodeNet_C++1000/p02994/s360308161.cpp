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
    int n, l;
    cin >> n >> l;

    int apple[n];
    int total = 0;
    int ans;
    int min_abs = 100000;
    rep(i, n) {
        apple[i] = l + i;
        total += apple[i];
        if(min_abs > abs(apple[i])) {
            min_abs = abs(apple[i]);
            ans = apple[i];
        }
    }
    cout << total - ans << endl;
}