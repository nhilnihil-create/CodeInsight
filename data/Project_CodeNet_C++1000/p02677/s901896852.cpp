/*
2020-05-05
atcoder ABC
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define EPS (1e-7)
#define INF (1e9)
#define PI 3.14159265358979323846264338327950L
const ll mod = 1000000007;

int main() {
    int A, B, H, M, T;
    long double ea, eb, e;
    cin >> A >> B >> H >> M;

    T = M + 60 * H;
    ea = T * 0.5;
    eb = T * 6;
    while(ea >= 360){
        ea -= 360;
    }
    while(eb >= 360){
        eb -= 360;
    }
    e = abs(ea-eb);
    e = min(360-e,e);
    cout << fixed << setprecision(20) << sqrt(pow(A, 2.0) + pow(B, 2.0) - 2 * A * B * cos(PI * e / 180)) << endl;

    return 0;
}
