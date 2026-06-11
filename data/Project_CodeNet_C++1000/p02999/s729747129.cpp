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
    int x, a;
    cin >> x >> a;

    int ans = 0;

    if(x >= a)
        ans = 10;

    cout << ans << endl;
}