#pragma GCC optimize("Ofast")
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define PI 3.141592
#define MOD 1000000007
#define LL_INF 9000000000000000000
#define LL_MINF -9000000000000000000
#define INT_INF 2000000000
#define INT_MINF -2000000000
#define all(a) (a).begin(), (a).end()
#define fi first
#define se second
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template<typename T>
T gcd(T a, T b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}
int main(){
    int ans = 0;
    int K;
    cin >> K;
    for(int i = 1; i <= K; i++)for(int j = 1; j <= K; j++) for(int k = 1; k <= K; k++){
        ans += gcd(gcd(i, j), k);
    }
    cout << ans << endl;
}
