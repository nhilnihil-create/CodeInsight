#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
typedef long long ll;

int main() {
    int N; cin >> N;
    vector<ll> height(N);
    for (int i = 0; i < N; i++) cin >> height[i];

    ll ma = 0, su  = 0;
    for (int i = 0; i < N; i++) {
        if (height[i] > ma) ma = height[i];
        su += ma - height[i];
    }
    cout << su << endl;
}
