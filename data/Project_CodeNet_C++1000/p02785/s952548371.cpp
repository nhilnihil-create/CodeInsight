#include <functional>
#include <iostream>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }
    sort(H.begin(), H.end(), greater<ll>());
    if (N <= K) {
        cout << 0 << endl;
        return 0;
    }
    ll sum = 0;
    for (int i = K; i < N; i++) {
        sum += H[i];
    }
    cout << sum << endl;
    return 0;
}

