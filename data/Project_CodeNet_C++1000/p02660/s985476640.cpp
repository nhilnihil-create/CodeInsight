// 有點不耐煩會破壞偉大的計劃

#include <bits/stdc++.h>

#define append push_back

using namespace std;
using ll = long long;

const int N = 1e5 + 3;
const int M = 1e6 + 7;
const long long MOD = 1e9 + 7;
const long long INF = 1e18 + 9;
const int SM = 1e3 + 5;
const int logN = 22, BL = 400;
const double EPS = 1e-9, PI = acos(-1);
const int dx[] = {1, 0, 0, -1, -1, 1, -1, 1};
const int dy[] = {0, 1, -1, 0, -1, 1, 1, -1};

void debug() {
	cerr << "\n";
}
template<typename Type1, typename... Type2>
void debug(Type1 a, Type2... b) {
    cerr << a << " ";
    debug(b...);
}

long long g(long long n) {
    long long sum = 0;
    if(n & 1) {
        sum = (n + 1) / 2;
        sum *= n;
    }
    else {
        sum = n / 2;
        sum *= (n + 1);
    }
    return sum;
}

long long f(long long n) {
    long long low = 1, high = MOD, m = 1;
    while(low <= high) {
        long long mid = low + (high - low) / 2;
        if(g(mid) <= n) {
            low = mid + 1;
            m = mid;
        }
        else {
            high = mid - 1;
        }
    }
    return m;
}

int main() {
//    freopen(".in", "r", stdin);
//    freopen(".out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    long long n; cin >> n;

    vector<long long> primes;

    for(long long i = 2; i * i <= n; i++) {
        long long cnt = 0;
        while(n % i == 0) {
            cnt++;
            n /= i;
        }
        if(cnt) primes.append(cnt);
    }

    if(n > 1) primes.append(1);

    long long ans = 0;
    for(auto cur : primes) {
        ans += f(cur);
    }

    cout << ans;

    return 0;
}
