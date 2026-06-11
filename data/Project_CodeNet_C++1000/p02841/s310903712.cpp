#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <functional>
#include <ccomplex>
#include <unordered_map>
#include <cstring>
#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>
#include <tuple>
#include <iomanip>

using namespace std;
#define MAX 1LL << 60
#define MOD 1000000007
#define BOX 200000

typedef long long ll;

#define rep(i, s, e) for(unsigned int i = s; i < e; i++)
#define repR(i, s, e) for(ll i = s; i > e; i--)
#define reft0(i, j) setfill('0') << setw(i) << j
#define fix(i) fixed << setprecision(i)
#define so(a) sort(begin(a), end(a))
#define soR(a) sort(begin(a), end(a), greater<ll>())
#define sum(a) accumulate(begin(a), end(a), 0)


template<class T> inline bool chMax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chMin(T& a, T b) { if (a > b) { a = b; return true; } return false; }



int main() {
    ll M1, D1, M2, D2;
    cin >> M1 >> D1 >> M2 >> D2;

    if (M1 != M2) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;

}