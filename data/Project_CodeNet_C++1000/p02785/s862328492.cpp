#include <iostream>
#include <string.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <vector>
#include <map>

using namespace std;

#define cn cout << '\n'
#define cio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define ii pair < int, int >
#define iii pair < int, ii >
#define INF 987654321
#define LINF 987654321987654321

ll bin(ll N, ll K, vector<ll> H) {
    if (K > N) return 0;
    ll l = 0;
    sort(H.begin(), H.end(), greater<>());
    for (int i = 0; i < N; ++i) {
        if (K > 0) K--;
        else l += H[i];
    }
    return l;
}

int main() {
    cio;
    ll N, K;
    cin >> N >> K;
    vector<ll> H(N);
    for (size_t i = 0; i < N; ++i) {
      cin >> H[i];
    }
    cout << bin(N, K, H);
    cn;
}
