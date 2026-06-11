#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <utility>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;
typedef pair<int, int> pair;
const int inf = 1000000000; //10^9

ll mon(ll h) {
    if (h == 1) return 1;

    return 2 * mon(h / 2) + 1;
}

int main(){
    ll h;
    cin >> h;

    cout << mon(h) << endl;

    return 0;
}