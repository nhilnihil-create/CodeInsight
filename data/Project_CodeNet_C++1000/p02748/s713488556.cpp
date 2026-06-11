// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define vv vector< vector< int > >
#define ll long long
#define ALL(a) (a).begin(), (a).end()
const long long mod = 1000000000 + 7;
const long long INF = 9e18;
const double PI = 3.14159265358979323846;

ll gcd(ll a, ll b){if (b == 0) return a;return gcd(b, a % b);}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }


int main(){
    int A, B, M, ans;
    cin >> A >> B >> M;
    vector<int> a(A), b(B);
    vector<int> X;
    vector<int> Y;
    vector<int> C;

    for(int i = 0; i < A; ++i) cin >> a[i];
    for(int i = 0; i < B; ++i) cin >> b[i];
    for(int i = 0; i < M; ++i){
        int x, y, c;
        cin >> x >> y >> c;
        x--; y--;
        X.push_back(x);
        Y.push_back(y);
        C.push_back(c);
    }
    ans = *min_element(a.begin(), a.end()) + *min_element(b.begin(), b.end());
    for(int i = 0; i < M; i++){
        ans = min(ans, a[X[i]] + b[Y[i]] - C[i]);
    }
    cout << ans << endl;
    return 0;
}
