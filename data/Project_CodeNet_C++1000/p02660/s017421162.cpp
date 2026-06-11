#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <tuple>
#include <algorithm>
#include <array>
#include <cmath>
using namespace std;
using ll = long long;
#define rep(i,n) for(decltype(n) i=0; i<n; ++i)
inline constexpr ll Inf = (1ULL << 62) -1;

template <class T>
void updatemax(T& a, T b) { if (b > a) a = b; }

int main() {
    ll N, ans=0;
    cin >> N;
    const int M = sqrt(N)+1;
    for (int i=2; i<=M && N!=1; i += (i==2)?1:2) {
        int d=0;
        for (; !(N%i); d++)
            N /= i;
        for (int e=1; d>=e; d -= e++)
            ans++;
    }
    if (N != 1)
        ++ans;
    cout << ans << endl;
    return 0;
}
