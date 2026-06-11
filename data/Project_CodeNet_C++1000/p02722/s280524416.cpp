#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int check(ll N, ll x) {
    if(x == 1) return 0;

    while(N % x == 0) N /= x;

    if(N % x == 1) return 1;
    else return 0;
}

int main() {
    ll N;
    cin >> N;

    ll ans = -1;

    for(ll i = 1; i * i <= N - 1; i++) {
        if((N - 1) % i == 0) {
            if(i * i == (N - 1)) {
                ans++;
            } else {
                ans += 2;
            }
        }
    }

    for(ll i = 1; i * i <= N; i++) {
        if(N % i == 0) {
            if(i * i == N) {
                ans += check(N, i);
            } else {
                ans += check(N, i);
                ans += check(N, N / i);
            }
        }
    }

    cout << ans << endl;
    return 0;
}
