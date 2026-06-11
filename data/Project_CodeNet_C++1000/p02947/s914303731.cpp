#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>
#include<functional>
using namespace std;
typedef long long ll;


long long GCD(long long a, long long b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}


int main() {
    int N;
    cin >> N;
    map<string, ll> s;
    for (int i = 0; i < N; i++) {
        string S;
        cin >> S;
        sort(S.begin(), S.end());
        s[S]++;
    }
    ll ans = 0;
    for (auto x : s) {
        ll n = x.second;
        ans += n * (n - 1) / 2;
    }
    cout << ans << endl;
}
