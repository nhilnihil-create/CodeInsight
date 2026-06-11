#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <math.h>
#include <cmath>
#include <climits>

typedef long long ll;
using namespace std;

ll MOD = 1e9+7;

int main() {
    ll h, w, n;
    cin >> h >> w >> n;
    vector<ll> vec(h);
    ll many = (n == 1e9 ? 1: n+1);
    for(int i = 0; i < w; i++){
        cout << n << " ";
    }
    for(int i = 0; i < h-w; i++){
        cout << many << " ";
    }
    cout << endl;
    return 0;
}