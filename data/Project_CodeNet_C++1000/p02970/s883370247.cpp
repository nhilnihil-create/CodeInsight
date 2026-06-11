#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L
const int mxN = 1e9 + 7;

char s[100005];
long long dp[100005][13];

int main() {
    int n, d;
    cin >> n >> d;
    int ans = (int)ceil((double)n / (double)((d * 2) +1));
    cout << ans;
    return 0;
}