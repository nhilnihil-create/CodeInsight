#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const long long INF = 1e15;

#include <math.h>
#define PI 3.14159265358979323846264338327950L



int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char color = s[0];
    int ans = 1;
    for (int i = 1; i < n; i++) {
        if (color != s[i]) {
            ans++;
            color = s[i];
        }
    }
    cout << ans;
    return 0;
}